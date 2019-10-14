#include "ex16.2.h"
#include <iostream>
#include <string>

int main()
{
    std::string s1("aaa"), s2("vvvv");
    int i = 8, j = 19;
    std::cout << compare(s1, s2) << std::endl;
    std::cout << compare(i, j) << std::endl;
    std::cout << compare("aaa", "vvvv") << std::endl;

    
    return 0;
}