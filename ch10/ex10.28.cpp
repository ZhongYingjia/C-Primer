#include <deque>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::deque;
int main()
{
    deque<int> v{1,2,3,4,5,6,7,8,9};
    deque<int> v1,v2,v3;
    
    //123456789
    std::copy(v.cbegin(),v.cend(),std::inserter(v1,v1.begin()));
    for(auto i : v1){
        std::cout << i <<" ";
    }
    std::cout << std::endl;

    //123456789
    std::copy(v.cbegin(),v.cend(),std::back_inserter(v2));
    for(auto i : v2){
        std::cout << i <<" ";
    }
    std::cout << std::endl;

    //987654321
    std::copy(v.cbegin(),v.cend(),std::front_inserter(v3));
    for(auto i : v3){
        std::cout << i <<" ";
    }
    std::cout << std::endl;


    
    
   

    
    
    
    return 0;
}