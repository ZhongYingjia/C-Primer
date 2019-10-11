#include <iostream>
#include <algorithm>
#include <vector>
class IsEqual{
    int val;
public:
    IsEqual(int v):val(v){}
    bool operator()(int elem){
        return elem == val;
    }
};

int main()
{
    std::vector<int> vi={1,2,3,4,5,6,7,8,9};
    std::replace_if(vi.begin(), vi.end(), IsEqual(3),5);
    for (int i : vi) std::cout << i << " ";
	std::cout << std::endl;

    return 0;
}