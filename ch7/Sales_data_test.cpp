#include <iostream>

#include "Sales_data.h"

using std::cout;using std::cin;using std::endl;


int main()
{
    Sales_data item1;
    print(cout,item1)<<endl;

    Sales_data item2("0-201-78345-X");
    print(cout,item2) << endl;
    
    Sales_data item3("0-201-78345-X",3,20.00);
    print(cout,item3)<<endl;

    Sales_data item4(std::cin);
	print(std::cout, item4) << endl;
    system("pause");
    return 0;
}