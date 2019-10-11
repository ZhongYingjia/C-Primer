#include <string>
#include <fstream>
#include <vector>
#include <iostream>
class BoundTest{
    size_t up;
    size_t low;
public:
    BoundTest(size_t l, size_t u):low(l),up(u){ }
    bool operator()(std::string str){
        return str.size() >= low && str.size() <= up;
    }
};

int main()
{
    std::ifstream ifs("../data/storyDataFile.txt");
    if(!ifs) return -1;
    int quantity9 = 0,quantity10 = 0;
    std::string str;
    BoundTest b(1,9);
    while(ifs >> str){
        if(b(str)) ++quantity9;
        else ++quantity10;
    }
    std::cout << quantity9 << " " << quantity10 << std::endl;
    
    return 0;


}