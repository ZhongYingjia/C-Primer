#include <iostream>
#include <vector>

using std::vector;

vector<int> *alloc()
{
    return new vector<int>();
}

void input(vector<int> *vp)
{
    for(int i; std::cin >> i; vp->push_back(i));
}

void output(vector<int> *vp)
{
    for(auto i : *vp){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    auto vp = alloc();
    input(vp);
    output(vp);
    delete vp;

   


    return 0;
}