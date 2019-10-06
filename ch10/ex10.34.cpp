#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

#include <iostream>
using std::vector;

int main()
{
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    //1
    for(auto rbeg = vi.crbegin(); rbeg != vi.crend(); ++rbeg){
        std::cout << *rbeg <<" ";
    }
    std::cout <<std::endl;
   
   //2
    for(auto iter = vi.cend(); iter != vi.cbegin();){
        std::cout << *--iter <<" "; 
    }
    std::cout <<std::endl;

    //3
    std::list<int> li{3, 7, 0, 3, 4, 0, 5};
    auto found = std::find(li.crbegin(),li.crend(),0);
    std::cout << *found << " in front of " << *found.base() << std::endl;

    //4
    std::list<int> l(7-3+1);
    std::reverse_copy(vi.cbegin()+3,vi.cbegin()+8,l.begin());
    for(auto i : l){
        std::cout << i << " ";
    }
    std::cout <<std::endl;

    
    
    return 0;
}