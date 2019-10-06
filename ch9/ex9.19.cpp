#include <string>
#include <list>
#include <iostream>

using std::list;
using std::string;

int main()
{
    list<string> ds;
    string input;
    while( std::cin >> input){
        ds.push_back(input);
    }
    for(list<string>::const_iterator dsi = ds.cbegin(); dsi != ds.cend(); ++dsi){
        std::cout << *dsi <<std::endl;
    }
    return 0;
    
}