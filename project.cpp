#include <iostream>
#include <vector>
#include <string>
class Database
{
private:
    std::vector<std::string> data;
public:
    void insert(const std::initializer_list<std::string>& records){
        for( const auto & record : records){
            data.push_back(record);
            std::cout << "inserted: \n";
        }
    }
    void showAll() const{
        std::cout <<"All record:\n";
        size_t i=0;
        while (i < data.size()){
            std::cout << i+1 << ":" << data[i] << "\n";
            i++;
        }
    }
    
};
int main(){
    Database db;
    int number=1;
    std::string record;


    std::cout <<"Menu:\n";
    std::cout <<"1.insert record\n";
    std::cout <<"2.update record\n";
    std::cout <<"3.find   record\n";
    std::cout <<"4.delet  record\n";
    std::cout <<"5.show all\n";
    std::cout <<"6.Exit\n";

    while (number!=6){
        std::cout <<"Enter number:";
        std::cin >> number;
       if ( number> 5  || number<1){
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
        else if( number == 6)
            std::cout << "Exiting.....\n";
    }
    
    return 0;

}