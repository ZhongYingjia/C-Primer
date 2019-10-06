#include <iostream>
int main()
{
    std::cout << "How long do you want to input?" << std::endl;
    int size = 0;
    std::cin >> size;
    char *input = new char[size+1];
    std::cin >> input;
    std::cout << input << std::endl;
    delete[] input;

    

    
    
    return 0;
    
}