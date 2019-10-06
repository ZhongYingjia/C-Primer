#include <memory>
#include <string>
#include <iostream>

using std::allocator;
using std::string;
int main()
{
    int n = 5;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while(std::cin >> s && q != p+n){
        alloc.construct(q++,s);
    }


    while( q!=p ){
        alloc.destroy(--q);
    }
    alloc.deallocate(p,n);
    return 0;

    

}