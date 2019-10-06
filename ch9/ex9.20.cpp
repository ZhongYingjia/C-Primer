#include <string>
#include <list>
#include <deque>
#include <iostream>

using std::list;
using std::string;
using std::deque;

int main()
{
    list<int> li{1,2,3,4,5,6,7,8,9,10};
    deque<int> odd, even;
    for(auto iter = li.cbegin(); iter != li.cend(); ++iter){
        if (*iter & 1){
            odd.push_back(*iter);
        }else{
            even.push_back(*iter);
        }
    }

    for(auto i : odd){
        std::cout << i <<" ";
    }
    std::cout << std::endl;

    for(auto i : even){
        std::cout << i <<" ";
    }
    std::cout << std::endl;
    


    return 0;
    
}