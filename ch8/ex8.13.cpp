#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

using std::istringstream;
using std::ostringstream;
using std::ifstream;

using std::cin;using std::cout;using std::endl;using std::cerr;

struct PersonInfo{
    string name;
    vector <string> phones;
};

bool valid(const string& str){
    return isdigit(str[0]);
}
string format(const string& str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    ifstream ifs("phonenumbers.txt");
    if(!ifs){
        std::cerr << "No data?" << std::endl;
        return 1;
    }
    
    string line;
    vector<PersonInfo> people;
    istringstream record;

    

    while(std::getline(ifs,line)){
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

    for(const auto& entry : people){
        ostringstream formatted,badNums;
        for(const auto& nums : entry.phones){
            if(!valid(nums)){
                badNums << " " <<nums;
            }else{
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) 
            cout << entry.name << " " <<formatted.str() << endl;
        else 
            cerr << "input error: " << entry.name << " invalid number(s) "
                 << badNums.str() << endl;

    }

    
    
    
    system("pause");
    return 0;
}