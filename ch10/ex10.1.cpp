#include <algorithm>
#include <vector>
#include <string>
#include <list>

#include <iostream>

int main()
{
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 6, 6, 2};
    std::cout << std::count(vi.begin(), vi.end(), 6) << std::endl;

    std::list<std::string> ls{"aa", "aaa", "aa", "cc"};
    std::cout <<std::count(ls.begin(), ls.end(), "aa") <<std::endl;

    return 0;

}