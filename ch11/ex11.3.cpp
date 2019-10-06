#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
using std::map;
using std::string;
int main()
{
    map<string,size_t> word_count;
    string word;
    while(std::cin >> word)
    {
        for(auto& i : word){
            i = tolower(i);
        }
        word.erase(std::remove_if(word.cbegin(),word.cend(),ispunct),word.end());
    }
    ++word_count[word];

    return 0;

}