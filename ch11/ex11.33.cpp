#include <map>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
using std::string;
using std::map;
using std::unordered_map;
using std::ifstream;
using std::istringstream;
using std::cout;using std::endl;

const string &transform(const string &str,const map<string,string> &trans_map);
map<string, string> buildMap(ifstream &map_file);

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string line;
    while(std::getline(input,line)){
        istringstream lineStream(line);
        string word;
        bool firstWord = true;
        while(lineStream >> word ){
            if(firstWord){
                firstWord = false;
            }else{
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;   
    }
}

map<string,string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;
    string value;
    while(map_file >> key && std::getline(map_file,value)){
        if(value.size() > 1){
            trans_map[key] = value.substr(1);
        }else{
            throw std::runtime_error("no rule for" + key);
        }
    }
    return trans_map;
}

const string & transform(const string &str, const map<string,string> &trans_map)
{
    auto map_it = trans_map.find(str);
    if(map_it != trans_map.cend()){
        return map_it -> second;
    }else{
        return str;
    }
}

int main()
{
    ifstream map_file("../data/word_transformation.txt");
    ifstream input("../data/word_transformation_bad.txt");

    word_transform(map_file,input);

    

    return 0;
}



