#ifndef EX13_31_H
#define EX13_31_H
#include <string>
#include <iostream>

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);
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

    void swap(HasPtr& rhs){
        using std::swap;
        swap(ps, rhs.ps);
        swap(i,rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    void show(){ std::cout << *ps <<std::endl; }
private:
    std::string *ps;
    int i;

};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
    lhs.swap(rhs);
    std::cout << "call swap(HasPtr&, HasPtr&)" << std::endl;
}

inline
bool operator<(const HasPtr& lhs, const HasPtr& rhs){
    return *lhs.ps < *rhs.ps;    
}

#endif