#include <iostream>
#include <vector>

template<typename T>
void print_container19(T& c)
{
    typedef typename T::size_type S;
    for(S i = 0; i != c.size(); ++i){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_container20(T& c)
{
    for(auto iter = c.begin(); iter != c.end(); ++iter){
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char const *argv[])
{
    std::vector<int> vi{1,2,3,4,5,6,7,8,9};
    print_container19(vi);
    print_container20(vi);
    return 0;
}
