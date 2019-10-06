#include <list>
#include <vector>
#include <string>
#include <iostream>

int main(){
    std::list<int> l1{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4, 5};
    std::vector<int> vec3{1, 2, 3, 4};
    std::cout << (std::vector<int>(l1.begin(),l1.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(l1.begin(),l1.end()) == vec3 ? "true" : "false") << std::endl;
    // std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
    // std::cout << std::boolalpha << (vec1 == vec3) << std::endl;

    return 0;
}