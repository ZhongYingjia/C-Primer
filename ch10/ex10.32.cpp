#include <iterator>
#include <vector>
#include <iostream>

#include <string>

#include <algorithm>
#include <numeric>
#include "Sales_item.h"

using std::vector;
using std::string;
int main()
{
    std::istream_iterator<Sales_item> in_iter(std::cin),in_eof;
    vector<Sales_item> vs;
    std::copy(in_iter,in_eof,std::back_inserter(vs));
    std::sort(vs.begin(),vs.end(),
                [](Sales_item const &s1,Sales_item const &s2)->bool{
                    return s1.isbn() < s2.isbn();
                });
    for(auto beg = vs.cbegin(),end = beg; beg != vs.cend(); beg = end)
    {
        end = std::find_if(beg, vs.cend(),
                            [beg](const Sales_item& item){
                                return item.isbn() != beg -> isbn();
                            });
        std::cout << std::accumulate(beg, end, Sales_item(beg ->isbn())) <<std::endl; 
        
    }
    

    
    
    
    return 0;
}