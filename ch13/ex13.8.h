#ifndef EX13_8_H
#define EX13_8_H
#include <string>

class HasPtr{
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)),i(0) { }
        
        HasPtr(const HasPtr &orig):
            ps(new std::string(*(orig.ps))),i(orig.i){ }

        HasPtr &operator=(const HasPtr &rhs){
            std::string *new_ps = new std::string(*rhs.ps);
            delete ps;
            ps = new_ps;
            i = rhs.i;
            return *this;
        }
    private:
        std::string *ps;
        int i;

};

#endif