#include "ex16.4.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>


int main()
{
    std::vector<int> vi{1,2,3,4,5,6,7,8,9};
    std::list<std::string> ls{"aa","bbb", "aaaaaa", "hhhhh"};
    std::cout << *find(vi.begin(), vi.end(), 5) << std::endl;
    std::cout << *find(ls.begin(), ls.end(), "aa") << std::endl;
    
    
    return 0;

}