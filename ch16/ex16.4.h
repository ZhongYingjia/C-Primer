#ifndef find_H
#define find_H

template<typename InputIt, typename T>
InputIt find(InputIt begin, InputIt end, const T& value)
{
    for(; begin != end; ++begin){
        if(*begin == value){
            return begin;
        }
    }
    return end;
}

#endif