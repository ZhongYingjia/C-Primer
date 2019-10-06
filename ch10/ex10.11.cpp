#include <algorithm>
#include <vector>
#include <string>

#include <iostream>
using std::string;

void elimDups(std::vector<string> & words)
{
    std::sort(words.begin(),words.end());
    auto end_unique = std::unique(words.begin(),words.end());

    words.erase(end_unique,words.end());

    
}

bool isShorter(const string& s1,const string& s2)
{
    return s1.size() < s2.size();
}

int main()
{
    std::vector<string> context{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    
    elimDups(context);
    std::stable_sort(context.begin(),context.end(),isShorter);

    for (const auto &i : context){
        std::cout << i << " ";
    }
    std::cout <<std::endl;
    
    


    return 0;
}