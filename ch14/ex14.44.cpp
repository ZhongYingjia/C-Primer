#include <functional>
#include <map>
#include <string>
#include <iostream>

int add(int i, int j){ return i + j; }

auto mod = [](int i, int j){ return i % j; };

struct divide{
    int operator()(int denominator, int divisor){
        return denominator / divisor;
    }
};

std::map<std::string, std::function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](int i, int j){ return i * j; }},
    {"/", divide()},
    {"%", mod}
};

int main()
{
    while(true){
        std::cout << "\npleasr enter: num operator num :\n";
        int i, j;
        std::string s;
        std::cin >> i >> s >> j;
        std::cout << binops[s](i, j) <<std::endl;
    }
    
}

