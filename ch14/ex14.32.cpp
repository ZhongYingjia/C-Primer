#include "ex14.32.h"
#include "StrBlob.h"
#include <iostream>

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p(&iter);
    std::cout << **p << std::endl;

    return 0;
}