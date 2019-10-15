#ifndef DebugDelete_H
#define DebugDelete_H

#include <iostream>
class DebugDelete{
public:
    DebugDelete(std::ostream &s = std::cerr):os(s) { }
    template <typename N> void operator()(N *p) const 
    { os << "deleting unique_ptr" << std::endl; delete p; }
private:
    std::ostream &os;
};


#endif
