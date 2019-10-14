#ifndef EX16_5_H
#define EX16_5_H
#include <iostream>

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for(auto &elem : arr){
        std::cout << elem << std::endl;

    }
}
#endif