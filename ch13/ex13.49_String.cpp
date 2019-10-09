#include "ex13.49_String.h"
#include <iostream>
#include <algorithm>
std::pair<char*, char*> String::alloc_n_copy(const char *b,const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char*c)
{
    //range_initializer
    char *cl = const_cast<char*>(c);
    while(*cl) ++cl;
    range_initializer(c,++cl);
}

String::String(const String&rhs)
{
    range_initializer(rhs.elements,rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String &&rhs) noexcept
    :elements(rhs.elements),end(rhs.end)
{
    rhs.elements = rhs.end = nullptr;
    std::cout << "move constructor" << std::endl;
}

String& String::operator=(String &&rhs) noexcept
{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    std::cout << "move-assignment" << std::endl;
    return *this;
}

void String::free()
{
    if(elements){
        std::for_each(elements,end,
            [this](char &c){
                alloc.destroy(&c);
            });
        alloc.deallocate(elements,end - elements);
        
    }
}
String::~String()
{
    free();
}

String& String::operator=(const String& rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;

}