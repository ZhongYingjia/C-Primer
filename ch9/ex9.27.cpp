#include <forward_list>
using std::forward_list;


int main()
{
    forward_list<int> a{0,1,1,2,3,5,8,13,21,55,89};
    auto pre = a.before_begin();
    auto cur = a.begin();
    while(cur != a.end()){
        if (*cur & 1){
            cur = a.erase_after(pre);
        }else{
            pre = cur;
            ++cur;
        }
    }


  

    return 0;
    
}