#include "ex13.39.h"
using std::string;
using std::pair;

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
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec &orig)
{
    auto newdata = alloc_n_copy(orig.begin(),orig.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
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

void StrVec::resize(size_t n, const std::string& str = "")
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
