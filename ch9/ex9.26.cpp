#include <vector>
#include <list>
using std::vector;
using std::list;


int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> vi(ia,std::end(ia));
    list<int> li(vi.begin(),vi.end());

    for(auto iter = vi.begin();iter != vi.end();){
        if (!(*iter & 1)){
            iter = vi.erase(iter);
        }else{
            ++iter;
        }
    }

    for(auto iter = li.begin();iter != li.end();){
        if (*iter & 1){
            iter = li.erase(iter);
        }else{
            ++iter;
        }
    }

    return 0;
    
}