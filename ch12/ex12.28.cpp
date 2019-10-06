#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream file("../data/storyDataFile.txt");
    string text;
    vector<string> input;
    map<string,set<decltype(input.size())>> wm;
    while(std::getline(file, text)){
        input.push_back(text);
        std::istringstream line(text);
        string word;
        auto lno = input.size() - 1;
        while(line >> word){
            wm[word].insert(lno);
        }
    }

    while(true){
        std::cout << "enter word to look for, or q to quit:";
        string s;
        if(!(std::cin >> s) || s == "q") break;
        std::cout << s << " occurs ";
        auto q = wm.find(s);
        if(q == wm.end()){
            std::cout << "0 time" << std::endl;
            continue;
        }else{
            std::cout << q->second.size() <<(q->second.size() > 1?" times":" time") << std::endl;
            for(auto i : q->second){
                std::cout << "\t(line " << i+1 << ") "
                << input[i] << std::endl;
            }
        }    
    }


    return 0;
}