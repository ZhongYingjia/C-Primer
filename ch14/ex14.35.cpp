#include <iostream>
#include <string>
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
    GetInput getInput;
    std::cout << getInput() << std::endl;
    return 0;
}