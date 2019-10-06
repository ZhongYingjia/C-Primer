#include <fstream>
#include <iostream>
#include "Sales_data.h"
using std::ifstream;
using std::ofstream;

int main(int argc, char**argv)
{
    Sales_data total;
    ifstream input(argv[1]);
    ofstream output(argv[2],ofstream::app);
    if (read(input, total)){
        Sales_data trans;
        while(read(input, trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }else{
                print(output,total) << std::endl;
                total = trans;
            }

        }
        print(output,total) << std::endl;
    }else{
        std::cerr << "No data?!" << std::endl;
    }

    //system("pause");
    return 0;
}