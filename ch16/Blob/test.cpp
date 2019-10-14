#include "Blob.h"
#include "BlobPtr.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Blob<std::string> bs{"aaa","bbb", "ccc"};
    Blob<std::string> bs2 = bs;
    bs2[2] = "ddd";

    if (bs == bs2) {
        for (auto iter = bs2.begin(); iter != bs2.end(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }

    


    return 0;
}
