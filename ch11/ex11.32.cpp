#include <map>
#include <set>
#include <string>
#include <iostream>
using std::multimap;
using std::map;
using std::multiset;
using std::string;

int main()
{
    multimap <string,string> authors{{"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
        {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"},
        {"pezy", "CP5"}
    };
    
    map<string,multiset<string> > orderedAuthor;
    for(const auto& author :authors){
        orderedAuthor[author.first].insert(author.second);
    }

    for(const auto &author : orderedAuthor){
        std::cout << author.first << ":";
        for(const auto &work : author.second){
            std::cout << work << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}