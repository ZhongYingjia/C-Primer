#include <iostream>
#include <vector>
using std::vector;

struct X{
    X(){ std::cout << "X()" << std::endl; }
    X(const X&){ std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X &rhs){
        std::cout << "X& operator=(const X &rhs)" << std::endl;
        return *this;
    }
    ~X(){
        std::cout << "~X()" << std::endl;
    }
};

void func(const X& crx, X x)
{
    vector<X> vx;
    vx.reserve(2);
    vx.push_back(crx);//X(const X&)
    vx.push_back(x);//X(const X&)
    //destory vec, ~X(),~X()
    //destory x,~X()
}

int main()
{
    X* px = new X;//X()
    func(*px, *px);//X(const X&):X x
    delete px;//~X()
    return 0;
}