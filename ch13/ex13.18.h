#ifndef EX13_18_H
#define EX13_18_H
#include <string>

class Employee{
    public:
        Employee(const std::string &nm):name(nm){
            id = base++;
        }
        Employee():Employee(""){ }

        const unsigned Id() const{
            return id;
        }

    private:
        std::string name;
        unsigned id;
        static unsigned base;
};

unsigned Employee::base = 0;

#endif