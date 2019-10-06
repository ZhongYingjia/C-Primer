#include <iostream>

int main(){
    //14
    {
        auto f = [](int i,int j)->int{return i+j;};
        std::cout << f(1,2) <<std::endl;
    }
    
    //15
    {
        int i = 5;
        auto f = [i](int j)->int{return i+j;};
        std::cout << f(2) <<std::endl;

    }
   

    
    
    
    return 0;
}