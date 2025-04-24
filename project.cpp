#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
class Schema{};
class DbInfo{};
class MetaData{};
class Record{};
class Database
{
private:
    vector<string> data;
public:
    void insert(const initializer_list<string>& records){
        for( const auto & record : records){
            data.push_back(record);
            cout << "inserted: \n";
        }
    }
    void showAll() const{
        cout <<"All record:\n";
        size_t i=0;
        while (i < data.size()){
            cout << i+1 << ":" << data[i] << "\n";
            i++;
        }
    }
    
};
int main(){
    Database db;
    int number=1;
    std::string record;


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