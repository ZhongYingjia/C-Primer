#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using std::vector;


int main()
{
    Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
        d4("CppCore"), d5("AwesomeCPP");
    vector<Sales_data> vs{d1,d2,d3,d4,d5};
    
    std::sort(vs.begin(),vs.end(),
                                [](Sales_data &sd1,Sales_data &sd2)->bool
                                { return sd1.isbn() < sd2.isbn(); });

    for(const auto& i : vs){
        std::cout << i.isbn() <<std::endl;
    }

    return 0;
}