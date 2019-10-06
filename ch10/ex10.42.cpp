#include <list>
#include <string>
#include <iostream>
using std::list;
using std::string;
void elimDups(list<string> &words){
    words.sort();
    words.unique();
}
int main()
{

    list<string> ls={"aa", "aa", "aa", "aa", "aasss", "aa"};
    elimDups(ls);
    for(const auto &word :ls) std::cout << word << " ";
    std::cout << std::endl;

    
    
    return 0;
}