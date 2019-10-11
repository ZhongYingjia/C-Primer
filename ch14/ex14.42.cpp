#include <functional>

int main()
{
    std::plus<int> intAdd;
    std::negate<int> intNegate;
    int sum = intAdd(10,20);
    sum = intNegate(intAdd(10,20));
    return 0;
}