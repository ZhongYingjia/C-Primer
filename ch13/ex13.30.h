#ifndef EX13_30_H
#define EX13_30_H
#include <string>
#include <iostream>

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
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
        ~HasPtr(){ delete(ps); }

        void show(){ std::cout << *ps <<std::endl; }
    private:
        std::string *ps;
        int i;

};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    std::cout << "call swap(HasPtr&, HasPtr&)" << std::endl;
}

#endif