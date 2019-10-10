#ifndef StrVec_H
#define StrVec_H


#include <string>
#include <memory>
#include <initializer_list>

class StrVec{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec():
        elements(nullptr),first_free(nullptr),cap(nullptr){ }
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;


    StrVec& operator=(const StrVec&);
    StrVec& operator=(std::initializer_list<std::string>);
    ~StrVec();

    std::string& operator[](size_t n) { return elements[n]; }
    const std::string& operator[](size_t n) const { return elements[n]; }

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t n, const std::string &str = std::string());
private:
    // static std::allocator<std::string> alloc;
    std::allocator<std::string> alloc;

    void chk_n_alloc(){
        if(size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);

    void alloc_n_move(size_t);
    void free();
    void reallocate();

    void range_initialize(const std::string*, const std::string*);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);


#endif