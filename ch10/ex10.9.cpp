#include <algorithm>
#include <vector>
#include <string>

#include <iostream>


void elimDups(std::vector<std::string> & words){
    std::sort(words.begin(),words.end());
    auto end_unique = std::unique(words.begin(),words.end());

    for(auto i : words){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    words.erase(end_unique,words.end());

    for(auto i : words){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}

int main()
{
    std::vector<std::string> context{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    
    for(auto i : context){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    elimDups(context);
    
    

    return 0;
}