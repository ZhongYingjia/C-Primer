#include <iostream>

int main()
{
    int i = 7;
    auto isZero = [&i]()->bool 
    {
        if(i != 0){
            --i;
            return false;
        }
        else return true;
    };

    for(unsigned j = 0;j != 10; ++j){
        std::cout << isZero() << " i = " << i <<std::endl;
    }

   

    
    
    
    return 0;
}