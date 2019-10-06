#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using std::vector;

inline
bool isShorter(Sales_data& s1,Sales_data& s2)
{
    return s1.isbn() < s2.isbn();
}

void compareIsbn(vector<Sales_data> & vsd)
{
    std::sort(vsd.begin(),vsd.end(),isShorter);
}

int main()
{
    Sales_data d1("CppPrimer"), d2("JavaCore"), d3("PythonCookBook"),
        d4("CppCore"), d5("AwesomeCPP");
    vector<Sales_data> vs{d1,d2,d3,d4,d5};
    compareIsbn(vs);

    for(const auto& i : vs){
        std::cout << i.isbn() <<std::endl;
    }

    return 0;
}