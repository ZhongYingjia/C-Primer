#include <iostream>
#include <string>

template <typename T>
std::ostream& print(std::ostream &os, const T &t){
    return os << t;
}

template <typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t,const Args& ... rest){
    os << t << ", ";
    return print(os, rest...);
}

int main(int argc, char const *argv[])
{
    int i = 9;
    std::string s = "hello, world";
    
    print(std::cout, i, s, 42);
    return 0;
}
