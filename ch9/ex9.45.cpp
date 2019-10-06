#include <string>
#include <iostream>

using std::string;

string pre_suffix(string& name, const string& pre, const string& su)
{
    name.insert(name.begin(),pre.begin(),pre.end());
    name.append(su.begin(),su.end());
    return name;
     
}

int main()
{
	string name ("Amy");
    pre_suffix(name, "Ms.","III");
    std::cout << name <<std::endl;
    return 0;
}