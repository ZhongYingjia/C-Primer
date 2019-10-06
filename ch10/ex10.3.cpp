#include <numeric>
#include <vector>

#include <iostream>

int main()
{
    std::vector<int> vi{1,2,3,4};
    std::cout << std::accumulate(vi.cbegin(),vi.cend(),0) << std::endl;

    

    return 0;

}