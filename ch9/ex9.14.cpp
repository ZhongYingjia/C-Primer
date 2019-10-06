#include <list>
#include <vector>
#include <string>

int main(){
    std::list<const char *> l{"hello","world","!"};
    std::vector<std::string> s;
    // auto lb = l.cbegin();
    // std::list<const char *>::const_iterator le = l.cend();
    s.assign(l.cbegin(),l.cend());

    return 0;
}