#ifndef EX16_2_H
#define EX16_2_H
#include<functional>
#include <cstring>

template<typename T>
int compare(const T &lhs, const T &rhs){
    if(std::less<T>()(lhs, rhs)) return 1;
    else if(std::less<T>()(rhs, lhs)) return -1;
    else return 0;
}

template<unsigned M, unsigned N>
int compare(const char (&p1)[M], const char (&p2)[N]){
    return strcmp(p1, p2);
}

#endif