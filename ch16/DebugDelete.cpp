#include "DebugDelete.h"
#include <memory>

int main(int argc, char const *argv[])
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);

    std::unique_ptr<int, DebugDelete> dp(new int, DebugDelete());



    return 0;
}
