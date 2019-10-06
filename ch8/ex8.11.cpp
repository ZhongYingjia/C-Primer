#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;using std::cout;using std::endl;
using std::istringstream;

struct PersonInfo{
    string name;
    vector <string> phones;
};

int main()
{
    string line;
    vector<PersonInfo> people;
    istringstream record;
    while(std::getline(cin,line)){
        record.clear();
        PersonInfo info;
        record.str(line);
        record >> info.name;
        string word;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (auto& p : people) {
        std::cout << p.name << " ";
        for (auto& s : p.phones) std::cout << s << " ";
        std::cout << std::endl;
    }
    
    
    system("pause");
    return 0;
}