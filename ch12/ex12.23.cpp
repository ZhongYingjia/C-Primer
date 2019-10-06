#include <cstring>
#include <memory>
#include <iostream>
int main()
{
    const char *c1 = "hello";
    const char *c2 = "world";
    unsigned len = strlen(c1) + strlen(c2) +1;
    char *c = new char[len]();
    strcat(c,c1);
    strcat(c,c2);
    std::cout << c << std::endl;
    delete[] c;

    const std::string s1("hello");
    const std::string s2("world");
    std::string *s = new std::string(s1+s2);
    std::cout << *s << std::endl;
    delete s;

    

    
    
    return 0;
    
}