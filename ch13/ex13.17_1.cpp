#include <iostream>

class numbered{
    public:
        numbered(){
            mysn = unique++;
        }
        unsigned mysn;

    private:
        
        static unsigned unique;
};

unsigned numbered::unique = 0;

void f(numbered s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);f(b);f(c);
    return 0;
}