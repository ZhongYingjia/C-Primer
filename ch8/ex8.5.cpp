#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;

void fToV(const string& fileName,vector<string>& vec)
{
    ifstream fstrm(fileName);
    if(fstrm){
        string buf;
        while(fstrm >> buf){
            vec.push_back(buf);
        }
    }
}

int main()
{
    vector<string> vec;
    fToV("add_item",vec);
    for(const auto &line : vec){
        std::cout << line <<std::endl;
    }
    system("pause");
    return 0;

}