#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
    {//a
        std::vector<int> vec;
        std::list<int> lst;
        int i;
        while(std::cin >> i){
            lst.push_back(i);
        }
        std::copy(lst.cbegin(),lst.cend(),std::back_inserter(vec));

    }
    
    
    {//b
        std::vector<int> vec;
        vec.resize(10);
        std::fill_n(vec.begin(),10,0);
        


    }
    

    return 0;
}