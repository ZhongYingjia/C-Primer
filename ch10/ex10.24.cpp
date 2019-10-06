#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using namespace std::placeholders;

bool check_size(const int num,string::size_type sz)
{
    return num > sz;
}



int main()
{
    // vector<string> context{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    // auto count = std::count_if(context.begin(),context.end(),bind(check_size,_1,6));
    vector<int> vi{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    string str = "heheheheh";
    auto it =  std::find_if(vi.begin(),vi.end(),bind(check_size,_1,str.size()));
    if(it != vi.end())std::cout << *it <<std::endl;
    

   

    
    
    
    return 0;
}