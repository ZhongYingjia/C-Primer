#ifndef EX13_19_H
#define EX13_19_H
#include <string>

class Employee{
    public:
        Employee(const std::string &nm):name(nm){
            id = base++;
        }
        Employee():Employee(""){ }

        Employee(const Employee&) = delete;
        Employee& operator=(const Employee&) = delete;

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