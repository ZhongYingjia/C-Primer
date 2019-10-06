#include <fstream>
#include <iostream>
#include "Sales_data.h"
using std::ifstream;

int main(int argc, char**argv)
{
    Sales_data total;
    ifstream input(argv[1]);
    if (read(input, total)){
        Sales_data trans;
        while(read(input, trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }else{
                print(std::cout,total);
                total = trans;
            }

        }
        print(std::cout,total);
    }else{
        std::cerr << "No data?!" << std::endl;
    }

    system("pause");
    return 0;
}