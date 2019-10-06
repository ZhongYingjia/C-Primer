#include <string>
#include <iostream>

using std::string;

void Replace(string& s, const string& oldVal, const string& newVal)
{
    for(decltype(s.size()) i = 0; i != s.size()-oldVal.size();){
        if (s[i] == oldVal[0] && s.substr(i,oldVal.size()) == oldVal){
            s.replace(i,oldVal.size(),newVal);
            i += newVal.size();
        }
        ++i;


    }
    
}

int main()
{
	string s("To drive straight thru is a foolish, tho courageous act.");
	Replace(s,"tho","though");
	Replace(s, "thru", "through");

	std::cout << s;
    return 0;
}