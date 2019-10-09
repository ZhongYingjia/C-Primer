#ifndef EX13_53_H
#define EX13_53_H
#include <string>
#include <iostream>

class HasPtr{
    friend void swap(HasPtr& ,HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)),i(0) { 
            std::cout << "call constructor" << std::endl;
        }
    
    HasPtr(const HasPtr &orig):
        ps(new std::string(*(orig.ps))),i(orig.i){ 
            std::cout << "call copy constructor" << std::endl;
        }
    HasPtr(HasPtr&& orig) noexcept:
        ps(orig.ps),i(orig.i){
            orig.ps = nullptr;
            std::cout << "call move constructor" << std::endl;
        }

    // HasPtr &operator=(const HasPtr &rhs){
    //     std::string *new_ps = new std::string(*rhs.ps);
    //     delete ps;
    //     ps = new_ps;
    //     i = rhs.i;
    //     return *this;
    // }

    HasPtr &operator=(HasPtr rhs){
        swap(*this, rhs);
        return *this;
    }
    ~HasPtr(){
        delete(ps);
        std::cout << "call destructor" << std::endl;
    }
private:
    std::string *ps;
    int i;

};

inline void swap(HasPtr& lhs,HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    std::cout << "call swap" << std::endl;
}

#endif