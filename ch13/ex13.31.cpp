#include "ex13.31.h"
#include <vector>
#include <algorithm>


//When the number of elements is too small,
// sort uses the insertion sorting algorithm and does not use swap.
//To increase the number of elements to a certain extent,
// sort uses a quick sortalgorithm
//which in this case uses a custom version of swap.
int main()
{
    std::vector<HasPtr> vh(500,HasPtr("bbcc"));
    vh.push_back(HasPtr("aaaaa"));
    vh.push_back(HasPtr("aa"));
    //std::vector<HasPtr> vh = {HasPtr("bbcc"),HasPtr("aaaaa"),HasPtr("aaaa"),HasPtr("bb")};
    for(auto &h: vh){ h.show(); }
    std::sort(vh.begin(),vh.end());
    for(auto &h: vh){ h.show(); }
    return 0;
}