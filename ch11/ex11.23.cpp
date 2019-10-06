#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using std::multimap;
using std::string;
using std::vector;
int main()
{
    // map<string, vector<string> > faml;
    // string lastName,childName;
    // while(
    //     [&]()->bool{
    //         std::cout << "Please enter last name:\n";
    //         return ((std::cin >> lastName) && (lastName != "@q"));
    //     }()
    // ){
    //     std::cout << "PLZ Enter children's name:\n";
    //     if((std::cin >> childName) && (childName!= "@q")){
    //         faml[lastName].push_back(childName);
    //     }
    // }

    // for(const auto &e : faml){
    //     std::cout << e.first <<std::endl;
    //     for(const auto &c: e.second){
    //         std::cout << c << " ";
    //     }
    //     std::cout << std::endl;
    // }
    multimap<string,string> family;
    for(string lastName,firstName; std::cin >> lastName >> firstName;family.emplace(lastName,firstName))
    ;
    for (const auto& s : family)
        std::cout << s.second << " " << s.first << std::endl;


    return 0;

}