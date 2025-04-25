#include <iostream>
#include <string>
using namespace std;
const int MAX_TABLES=10;
const int MAX_RECORDS=50;
class Column{
    private:
     string name;
     string type;
    public:
    Column():name(""),type(""){}
    Column(const string& colName,const string& colType):name(colName), type(colType){}
    string getName() const{
        return name;
    }
    string getType() const{
        return type;
    }
    void setName(const string& colName){
        name=colName;
    }
    void setType(const string& colType){
        type=colType;
    }
};
class Schema{
    private:
     string tableName;
     Column columns[15];
     int columnCount;
    public:
     Schema(): tableName(""),columnCount(0){}
     Schema(const string& name):tableName(name), columnCount(0){}
     string getName() const{
        return tableName;
     }
     void addColumn(const string& colName, const string& colType){
        if(columnCount<15){
            columns[columnCount++]=Column(colName, colType);
        }else{
            cout<<"you can't insert any new columns"<<endl;
        }
     }
     void printSchema() const{
        cout<<"table:"<<tableName<<endl;
        for(int i=0;i<columnCount;i++){
            cout<<"column"<<(i+1)<<":"<<columns[i].getName()<<" ("<<columns[i].getType()<<")"<<endl;
         }
        }
     int getColumnCount() const{
        return columnCount;
     }
     Column* getColumn(int index){
        return &columns[index];
     }
     Column* getColumn(int index){
        return &columns[index];
     }
};
class DbInfo{
    private:
     Schema tables[MAX_TABLES];
     int tableCount;
    public:
     DbInfo():tableCount(0){}
     bool addTable(const string& tableName){
        if(tableCount<MAX_TABLES){
            tables[tableCount++]=Schema(tableName);
            return true; 
        }
        
        return false;
     }
     bool removeTable(const string tableName) {
        for(int i=0;i<tableCount;i++){
            if(tables[i].getName()==tableName){
                for(int j=i;j<tableCount-1;j++){
                    tables[j]=tables[j+1];
                }
                tableCount--;
                return true;
            }

        }
        return false;
     }
     void printTables() const{
        for (int i=0;i<tableCount;i++){
            cout<<tables[i].getName()<<endl;

     }
    }
    Schema* getTable(const string& tableName){
        for(int i=0;i<tableCount;i++){
            if(tables[i].getName()==tableName){
                return &tables[i];
            }
        }
        return nullptr;
    }
    bool hasTable(const string& tableName){
        for(int i=0;i<tableCount;i++){
            if(tables[i].getName()==tableName){
                return true;
            }
        }
        return false;
    }
};
class MetaData{
    private:
     string* recordData;
     int columnCount;
    public:
     MetaData(int colCount): columnCount(colCount){
        recordData= new string[columnCount];
     }
     ~MetaData(){
        delete[] recordData;
     }
    void setData(int index, const string& data){
        if(index>=0 && index<columnCount){
            recordData[index]= data;
        }
    }
    string getData(int index) const{
        if(index>=0 &&index<columnCount){
            return recordData[index];
        }
        return "";
    }
    void printRecord() const{
        for (int i=0; i<columnCount;i++){
            cout<<recordData[i]<<" ";
        }
    }
    int getColumnCount() const{
        return columnCount;
    }

};
class Record{
 private:
    string tableName;
    bool isDeleted;
    MetaData* metaData;
 public:
    Record(const string& tableName,int columnCount): tableName(tableName),isDeleted(false){
        metaData=new MetaData(columnCount);
    }
    ~Record(){
        delete metaData;
    }
    void setData(int index,const string& data){
        metaData->setData(index, data);
    }
    string getData(int index){
        return metaData->getData(index);
    }
    void markAsDeleted(){
        isDeleted=true;
    }
    bool getIsDeleted()const{
        return isDeleted;
    }
    void printRecord()const{
        if(!isDeleted){
            cout<<"Table: "<<tableName;
            metaData->printRecord();
        }
    }
    string getTableName()const{
        return tableName;
    }
    int getColumnCount() const{
        return metaData->getColumnCount();
    }


};


class DataBase
{
private:
    Record* records[MAX_RECORDS];
    int recordCount;
public:
    DataBase() :recordCount(0){}

    bool insertRecord(const string& tableName, Schema& schema) {
        if (recordCount < MAX_RECORDS) {
            int columnCount = schema.getColumnCount();
            Record* newRecord = new Record(tableName, columnCount);
    
            // Show columns to the user and ask which column to insert data into
            cout << "Columns available in '" << tableName << "':\n";
            for (int i = 0; i < columnCount; i++) {
                cout << (i + 1) << ". " << schema.getColumn(i)->getName() << "\n";
            }
    
            // Ask the user to choose a column number
            int colChoice;
            cout << "Enter the number of the column to insert data into: ";
            cin >> colChoice;
            cin.ignore(); // Ignore newline left by previous input
    
            if (colChoice < 1 || colChoice > columnCount) {
                cout << "Invalid column selection.\n";
                delete newRecord;
                return false;
            }
    
            // Now, prompt the user to input the data for the selected column
            string colData;
            cout << "Enter data for column '" << schema.getColumn(colChoice - 1)->getName() << "': ";
            getline(cin, colData);
    
            // Insert data into the chosen column
            newRecord->setData(colChoice - 1, colData);
    
            // Store the new record
            records[recordCount++] = newRecord;
            cout << "Record inserted into column " << colChoice << ".\n";
            return true;
        }
    
        cout << "Unable to insert record: Database is full.\n";
        return false;
    }
    void findRecords(const string& tableName, const string& columnName, const string& value)
    {
        for(int i=0; i<recordCount;i++){
            if(records[i]->getTableName()== tableName){
                for(int j=0; j<records[i]->getColumnCount();j++){
                    if(records[i]->getData(j)== value){
                        records[i]->printRecord();
                    }
                }
            }
        }
    }

    void updateRecord(const string& tableName, const string& columnName, const string& oldValue, const string& newValue){
        for(int i=0;i<recordCount; i++){
            if(records[i]->getTableName()== tableName){
                for(int j=0; j<records[i]-> getColumnCount(); j++){
                    if(records[i]->getData(j) == oldValue){
                        records[i]->setData(j, newValue);
                    }
                }
            }
        }
    }

    void deleteRecord(const string& tableName, const string& columnName, const string& value) {
        for (int i = 0; i < recordCount; ++i) {
            if (records[i]->getTableName() == tableName) {
                for (int j = 0; j < records[i]->getColumnCount(); ++j) {
                    if (records[i]->getData(j) == value) {
                        records[i]->markAsDeleted();
                    }
                }
            }
        }
    }

    void printAllRecords() const {
        for (int i = 0; i < recordCount; ++i) {
            records[i]->printRecord();
        }
    }
};
int main(){
    DbInfo db;
    DataBase myDB;
    int choice;
    do{
    cout <<"\nMenu:\n";
    cout <<"1.add table\n";
    cout <<"2.add column\n";
    cout <<"3.add record\n";
    cout <<"4.update record\n";
    cout <<"5.delete record\n";
    cout <<"6.show all record\n";
    cout <<"7.Find Record\n";
    cout <<"8.exit\n";
    cout<<"enter a number: ";
    cin>>choice;

    switch(choice){
        case 1:{
            string tableName;
            cout<<"enter table name: ";
            cin>>tableName;
            db.addTable(tableName);
            cout<<tableName<<" added"<<endl;
            break;
        }
        case 2:{
            string tableName, colName, colType;
            cout<<"enter table name to add column: ";
            cin>>tableName;
            cout<<"enter column name: ";
            cin>>colName;
            cout <<"enter column's data type(string,number,ect..): ";
            cin>>colType;
            
            if(db.hasTable(tableName)){
                Schema* schema=db.getTable(tableName);
                schema->addColumn(colName,colType);
                cout<<"column added"<<endl;
            } else{
                cout<<"table not found"<<endl;
                //break;
            }
            break;
         }
         case 3:{
            string tableName;
            cout << "Enter table name to add record: ";
            cin >> tableName;
        
            if (db.hasTable(tableName)){
                Schema* schema = db.getTable(tableName);
                myDB.insertRecord(tableName, *schema);} 
             else{
                cout << "Table not found\n";
            }
            break;
        }

        }
        case 4:{
            string tableName, columnName, oldValue, newValue;
            cout<<"enter table name to update record: ";
            cin>>tableName;
            cout<<"enter column name: ";
            cin>>columnName;
            cout<< "enter old value: ";
            cin>>oldValue;
            cout<< "enter new value: ";
            cin>> newValue;
            myDB.updateRecord(tableName, columnName,oldValue,newValue);
            cout<<"value updated."<<endl;
            break;

        }
        case 5:{
            string tableName, columnName, value;
            cout<<"enter table name to delete record: ";
            cin>>tableName;
            cout<<"enter column name: ";
            cin>>columnName;
            cout<< "enter your value: ";
            cin>>value;
            myDB.deleteRecord(tableName,columnName,value);
            cout<<"value deleted"<<endl;
            break;
        }
        case 6:{
            myDB.printAllRecords();
            break;
        }
        case 7:{
            string tableName, columnName, value;
            cout << "Enter table name to search in: ";
            cin.ignore();
            getline(cin, tableName);
            cout << "Rnter value to search for: ";
            getline(cin, value);
            myDB.findRecords(tableName, columnName, value);
            break;
        }
        case 8:{
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    }while (choice!=8);
    
    
    return 0;

}