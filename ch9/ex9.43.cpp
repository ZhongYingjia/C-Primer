#include <string>
#include <iostream>

using std::string;

void Replace(string& s, const string& oldVal, const string& newVal)
{
    for(auto beg = s.begin();std::distance(beg, s.end()) >= std::distance(oldVal.begin(),oldVal.end());){
        if((string(beg,beg + oldVal.size())) == oldVal){
            beg = s.erase(beg,beg + oldVal.size());
            beg = s.insert(beg,newVal.begin(),newVal.end());
            beg += newVal.size();
        }
        ++beg;
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