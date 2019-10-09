#include "ex13.49_StrVec.h"
#include <algorithm>
using std::string;
using std::pair;
using std::initializer_list;

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements){
        // for(auto p = first_free; p != elements;){
        //     alloc.destroy(--p);
        // }
        std::for_each(elements,first_free,
            [this](string &rhs){ alloc.destroy(&rhs); });

        
        alloc.deallocate(elements, cap-elements);
    }
}

void StrVec::range_initialize(const std::string *beg, const std::string *ed)
{
    auto newData = alloc_n_copy(beg, ed);
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::StrVec(initializer_list<string> ls)
{
    range_initialize(ls.begin(),ls.end());
}

StrVec::StrVec(const StrVec &orig)
{
   range_initialize(orig.begin(), orig.end());
}

StrVec::~StrVec()
{
    free();
}

StrVec::StrVec(StrVec&& s) noexcept
    :elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    elements = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t n)
{
    auto newData = alloc.allocate(n);

    auto dest = newData;
    auto elem = elements;

    for(size_t i =0; i!=size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = elements + n;

}

void StrVec::reallocate()
{
    auto newCapacity = size() ? 2 * size() : 1;
    alloc_n_move(newCapacity);
}

void StrVec::reserve(size_t n)
{
    if(n <= size()) return;
    alloc_n_move(n);
}

void StrVec::resize(size_t n, const std::string &str = std::string())
{
    if(n<=size()){
        while(first_free != elements + n){
            alloc.destroy(--first_free);
        }
    }else{
        if(n > capacity()) reserve(n * 2);
        for(size_t i = 0; i != n-size(); ++i){
            alloc.construct(first_free++, str);
        }
    }
}