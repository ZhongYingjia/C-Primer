#include <map>
#include <string>
#include <iostream>
using std::multimap;
using std::string;

int main()
{
    multimap <string,string> authors{{"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
        {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"},
        {"pezy", "CP5"}
    };
    string author = "wang";
    string work = "CP5";
    auto iter  = authors.find(author);
    //unsigned count = authors.count(author);

    while( iter!= authors.end() && iter -> first == author ){
        if( iter ->second == work)
            iter = authors.erase(iter);
        else
            ++iter;
    }

    for(const auto &a : authors){
        std::cout << a.first << " " << a.second << std::endl;

    }


    return 0;

}