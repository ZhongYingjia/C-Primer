#include <string>
#include <fstream>
#include <vector>
#include <iostream>
class BoundTest{
    size_t threshold;
public:
    BoundTest(size_t ts):threshold(ts){ }
    bool operator()(std::string str){
        return str.size() == threshold;
    }
};

int main()
{
    std::ifstream ifs("../data/storyDataFile.txt");
    if(!ifs) return -1;
    std::vector<int>quantitys(10,0);
    std::string str;
    while(ifs >> str){
        for(int i = 0; i != 11; ++i){
            BoundTest boundTest(i);
            if(boundTest(str)) ++quantitys[i];
        }
    }
    std::cout << "The number of words with a length of 1-10 is, in turn:"<<std::endl;
    for(auto i :quantitys){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;


}