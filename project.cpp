#include <iostream>
#include <vector>
#include <string>
class Database
{
private:
    std::vector<std::string> records;
public:
    void insert(const std::string& record){
        records.push_back(record);
    }
    void showAll() const{
        std::cout <<"All record:\n";
        size_t i=0;
        while (i < records.size()){
            std::cout << i+1 << ":" << records[i] << "\n";
            i++;
        }
    }
    
};
int main(){
    Database db;
    int number=1;
    std::string record;


    std::cout << "menu:\n";
    std::cout <<"1.insert record\n";
    std::cout <<"2.update record\n";
    std::cout <<"3.find   record\n";
    std::cout <<"4.delet  record\n";
    std::cout <<"5.show all\n";
    std::cout <<"6.exit\n";

    while (number!=6){
        std::cout <<"enter number:";
        std::cin >> number;
       if ( number> 6  || number<1){
           std::cout << "Error\n";
            return 0;
        }
        if ( number == 1){
            std::cout << "Enter record:\n";
            std::cin.ignore();
            std::getline (std::cin, record);
            db.insert(record);
        }
        else if( number == 5){
            db.showAll();
        }
    }    
    return 0;

}