#include <iostream>
#include <vector>
#include <string>
class Database
{
private:
    std::vector<std::string> records;
public:
    void insert(std::string& record){
        records.push_back(record);
        std::cout << "OK\n";
    }
    
};
int main(){
    Database db;
    int chos;
    std::string record;


    std::cout << "menu:\n";
    std::cout <<"1.insert record\n";
    std::cout <<"2.update record\n";
    std::cout <<"3.find record\n";
    std::cout <<"4.delet record\n";
    std::cout <<"enter number";
    std::cin >> chos;

    if ( chos>4  || chos<1){
        std::cout << "Error\n";
        return 0;
    }
    else if ( chos == 1){
        std::cin.ignore();
        std::getline (std::cin, record);
        db.insert(record);
    }
    return 0;

}