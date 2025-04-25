#include <iostream>
#include <vector>
#include <string>
using namespace std;
const MAX_TABLES=10;
const MAX_RECORDS=50;
class Column{
    private:
     string name;
     string type;
    public:
    Column():name(""),type(""){}
    Column(const string colName,const string colType):name(colName), type(colType){}
    string getName() const{
        return name;
    }
    string getType() const{
        return type;
    }
    void setName(const string colName){
        name=colName;
    }
    void setType(const string colType){
        name=colType;
    }
};
class Schema{
    private:
     string tableName;
     Column columns[15];
     int columnCount;
    public:
     Schema(): tableName(""),columnCount(0){}
     Schema(const string name):tableName(name), columnCount(0){}
     string getName() const{
        return tableName;
     }
     void addColumn(const string colName, const string colType){
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
     Column* getColumnCount(int index){
        return &columns[index];
     }
};
class DbInfo{
    private:
     Schema tables[MAX_TABLES];
     int tableCount;
    public:
     DbInfo():tableCount(0){}
     bool addTable(const string tableName){
        if(tableCount<MAX_TABLES){
            tables[tableCount++]=Schema(tableName);
        }
        return false;
     }
     bool removeTable(const string tableName) {
        for(int i=0;i<tableCount;i++){
            if(tables[i].getName()==tableName){
                for(int j=i;j<tableCount;j++){
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
    Schema* getTable(const string tableName){
        for(int i=0;i<tableCount;i++){
            if(tables[i].getName()==tableName){
                return &tables[i];
            }
        }
        return nullptr;
    }
    bool hasTable(const string tableName){
        for(int t=0;i<tableCount;i++){
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
    void setData(int index, const string data){
        if(index>=0 &&index<columnCount){
            recordData[index]= data;
        }
    }
    string getData(int index) const{
        if(index>=0&&index<columnCount){
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
    Record(const string tableName,int columnCount): tableName(tableName),isDeleted(false){
        metaData=new MetaData(columnCount);
    }
    ~Record(){
        delete[] metaData;
    }
    void setData(){}
    string getData(){}
    void markAsDeleted(){
        isDeleted=true;
    }
    bool getIsDeleted()const{
        return isDeleted;
    }
    void printRecord()const{}
    string getTableName()const{
        return tableName;
    }
    int getColumnCount() const{}


};


class Database
{
private:
    Record*record[MAX_RECORDS];
    int recordCont;
public:
    Database() :recordCount(0){}

    bool insertRecord(const string& tableName, const Schema& schema, const string data[]){
        if(recordCont < MAX_RECORDS ){
            int clumnCount =schema.getColumnCount();
            Record*newRecord = new Record)tableName, columnCount);

            for(int i=0, i< columnCount; i++){
                newRecord->setData(i, data[i]);
            }

            record[recordCont++] = newRecord;
            return true;
        }
        return false;
    }
    void findRecords(const string& rableName, const string& colunmName, const string& value){
        for(int i=0; i<recordCount;i++){
            if(records[i]->getTableName()== tableName){
                for(int j=0; j<records[i]->getColumnCount();j++){
                    if(records[i]->getData(j)== value){
                        recosi[i]->printRecord();
                    }
                }
            }
        }
    }

    void updateRecord(const string& tableName, const string& columnName, const string& oldValue, const string& newValue){
        for(int i=0;i<recordCont; i++){
            if(records[i]->gerTableName()== tableName){
                for(int j=0; j<records[i]-> gerClumnCount(); j++){
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
    Database db;
    Database 
    string record;


    cout <<"Menu:\n";
    cout <<"1.insert record\n";
    cout <<"2.update record\n";
    cout <<"3.find   record\n";
    cout <<"4.delet  record\n";
    cout <<"5.show all\n";
    cout <<"6.Exit\n";

    while (number!=6){
        cout <<"Enter number:";
        cin >> number;
       if ( number> 5  || number<1){
           cout << "Error\n";
            return 0;
        }
        if ( number == 1){
            cout << "Enter record:\n";
            cin.ignore();
            getline (cin, record);
            db.insert(record);
        }
        else if( number == 5){
            db.showAll();
        }
        else if( number == 6)
            cout << "Exiting.....\n";
    }
    
    return 0;

}