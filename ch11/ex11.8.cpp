#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using std::map;
using std::string;
using std::vector;
int main()
{
    vector<string> words;
    for(string word; std::cin >> word;){
        // if(words.empty()){
        //     words.push_back(word);
        //     continue;
        // }
        if(std::find(words.begin(),words.end(),word) != words.end()){
            std::cout << "<Repeating element>" <<std::endl;
        }else{
            words.push_back(word);
        }
    }
    for(const auto &w :words){
        std::cout << w <<" ";
    }
    std::cout << std::endl;




    return 0;

}