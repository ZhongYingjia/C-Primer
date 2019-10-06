#include <string>
#include <utility>
#include <vector>
#include <iostream>


using std::vector;
using std::string;
using std::pair;
int main()
{
    string str;
    int num;
    vector<pair<string, int>> vp;
    while( std::cin >> str >> num)
    {
        // vp.push_back({str,num});
        // vp.push_back(std::make_pair(str,num));
        // vp.push_back(pair<string,int>(str,num));
        vp.emplace_back(str,num);
    }

    for(const auto &e : vp){
        std::cout << e.first << ":" <<e.second << std::endl;
    }

    return 0;

}