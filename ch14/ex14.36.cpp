#include <iostream>
#include <string>
#include <vector>
class GetInput{
public:
    GetInput(std::istream& is_ = std::cin):is(is_){ }
    std::string operator()(){
        std::string ret;
        std::getline(is,ret);
        return is ? ret : std::string();
    }

private:
    std::istream& is;
};

int main()
{
    std::vector<std::string> vs;
    GetInput getInput;
    for(std::string tmp; !(tmp = getInput()).empty() ;){
        vs.push_back(tmp);
    }
    return 0;
}