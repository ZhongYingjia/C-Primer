#include <iostream>
#include <string>
using std::string;

#include <sstream>


template <typename T>
string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if(p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

template <typename T>
std::ostream& print(std::ostream &os, const T &t){
    return os << t;
}

template <typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t,const Args& ... rest){
    os << t << ", ";
    return print(os, rest...);
}

template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&...rest)
{
    return print(os, debug_rep(rest)...);
}

int main(int argc, char const *argv[])
{
    string s = "hhhhhh";
    int i = 0;
    double j = 8;
    errorMsg(std::cout, s, i, j);
    return 0;
}
