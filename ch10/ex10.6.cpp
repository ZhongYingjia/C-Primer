#include <algorithm>
#include <iterator>
#include <vector>

#include <iostream>
int main()
{
    std::vector<int> vi{1,2,3,4,5,6,7,8,9};
    std::fill_n(vi.begin(),vi.size(),0);

    for(auto i : vi){
        std::cout << i << " ";
    }
    std::cout << std::endl;


    

    return 0;

}