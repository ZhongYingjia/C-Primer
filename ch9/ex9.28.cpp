#include <forward_list>
#include <string>
using std::forward_list;
using std::string;

void func(forward_list<string> & list, const string& find, const string& insert)
{
    for(auto iter = list.begin(); iter != list.end(); ++iter){
        if (*iter == find){
            list.insert_after(iter,insert);
            return;
        }
    }
    list.insert_after(list.end(),insert);
}

