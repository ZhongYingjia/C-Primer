#include <iostream>
#include "StrBlob.h"
int main()
{
    //16
    // StrBlob sb{"Hello", "World", "Pezy"};

    // for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
    //     std::cout << iter.deref() << " ";
    // }
    // std::cout << std::endl;

    //18
    // StrBlob sb1{"a", "b", "c"};
    // StrBlob sb2{"a", "b", "b"};

    // if (sb1 > sb2) {
    //     for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend();
    //          iter.incr())
    //         std::cout << iter.deref() << " ";
    //     std::cout << std::endl;
    // }
    
    //26
    // StrBlob sb1{"a", "b", "c"};
    // StrBlob sb2 = sb1;

    // sb2[2] = "b";

    // if (sb1 > sb2) {
    //     for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend();
    //          iter.incr())
    //         std::cout << iter.deref() << " ";
    //     std::cout << std::endl;
    // }

    // StrBlobPtr iter(sb2);
    // std::cout << iter[2] << std::endl;

    //27
    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (StrBlobPtr iter = sb1.begin(); iter < sb1.end(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << *(iter + 2) << std::endl;
    return 0;
}