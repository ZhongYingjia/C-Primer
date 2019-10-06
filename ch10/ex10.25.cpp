#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;
using namespace std::placeholders;

void elimDup(vector<string> &words){
    std::sort(words.begin(),words.end());
    auto unique_end = std::unique(words.begin(),words.end());
    words.erase(unique_end,words.end());
}
bool check_size(const string&s,string::size_type sz)
{
    return  s.size() < sz;
}


void biggest(vector<string> &words,vector<string>::size_type sz)
{
    elimDup(words);
    std::stable_sort(words.begin(),words.end(),
                    [](const string&s1,const string&s2)->bool
                    { return s1.size() < s2.size();});
    auto wc = std::partition(words.begin(),words.end(),std::bind(check_size,_1,sz));

    // auto wc = std::stable_partition(words.begin(),words.end(),
    //                         [sz](const string &str)->bool
    //                         { return str.size() < sz; });

    auto count = words.end() - wc;
    std::cout << "count:" << count << std::endl;
    std::for_each(wc,words.end(),
                [](const string &word)
                { std::cout << word << " "; });
    std::cout <<std::endl;



}
int main()
{
    vector<string> context{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    biggest(context,4);
    
   

    
    
    
    return 0;
}