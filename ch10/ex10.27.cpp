#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::vector;
using std::string;
int main()
{
    vector<string> context{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    std::sort(context.begin(),context.end());
    vector<string> vs2;
    std::unique_copy(context.begin(),context.end(),std::back_inserter(vs2));

    for (auto &i : vs2){
        std::cout << i << " ";

    }
    std::cout << std::endl;

    
   

    
    
    
    return 0;
}