#include <string>
#include <iostream>

using std::string;

string pre_suffix(string& name, const string& pre, const string& su)
{
    name.insert(0,pre);
    name.insert(name.size(),su);
    
    return name;
     
}

int main()
{
	string name ("Amy");
    pre_suffix(name, "Ms.","III");
    std::cout << name <<std::endl;
    return 0;
}