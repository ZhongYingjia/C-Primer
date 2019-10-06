#include <iostream>
#include <vector>
#include <memory>

using std::vector;

std::shared_ptr<vector<int>> alloc()
{
    return std::make_shared<vector<int>>();
}

void input(std::shared_ptr<vector<int>> spv)
{
    for(int i; std::cin >> i; spv->push_back(i));
}

void output(std::shared_ptr<vector<int>> spv)
{
    for(auto i : *spv){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    auto spv = alloc();
    input(spv);
    output(spv);


   


    return 0;
}