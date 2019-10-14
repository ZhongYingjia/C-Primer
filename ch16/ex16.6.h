#ifndef EX16_6_H
#define EX16_6_H

template<typename T, unsigned N>
T* begin(T (&arr)[N])
{
    return &arr[0];
}

template<typename T, unsigned N>
T* end(T (&arr)[N])
{
    return &arr[N];
}



#endif