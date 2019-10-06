#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

int main()
{
    vector<char> vc{'H','e','l','l','o'};
    string str(vc.begin(),vc.end());
    std::cout << str <<std::endl;
    return 0;
}
