#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::vector;
using std::string;

bool predicate(const string&s){
    return s.size() >= 5;
}



int main()
{
    vector<string> vs={"a","as", "aasss","aaaaassaa", "aaaaaabba", "aaa"};
    auto pivot=std::partition(vs.begin(),vs.end(),predicate);

    for (auto it = vs.cbegin(); it != pivot; ++it) std::cout << *it << " ";
    std::cout << std::endl;
    

    return 0;
}