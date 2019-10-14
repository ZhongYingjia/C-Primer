#ifndef EX16_7_H
#define EX16_7_H

template<typename T, unsigned N>
constexpr unsigned size_of_array(const T (&arr)[N]){
    return N;
}


#endif