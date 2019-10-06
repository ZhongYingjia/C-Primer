#include <iostream>
#include <string>
#include <memory>
using std::string;


int main(){

    std::unique_ptr<int> p(new int(42));
    //std::unique_ptr<int> p2(p);
    
    return 0;
}