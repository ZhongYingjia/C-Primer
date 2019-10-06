#include <string>
#include <deque>
#include <iostream>

using std::deque;
using std::string;

int main()
{
    deque<string> ds;
    string input;
    while( std::cin >> input){
        ds.push_back(input);
    }
    for(deque<string>::const_iterator dsi = ds.cbegin(); dsi != ds.cend(); ++dsi){
        std::cout << *dsi <<std::endl;
    }
    return 0;
    
}