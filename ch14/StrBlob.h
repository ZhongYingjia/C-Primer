#ifndef StrBlob_H
#define StrBlob_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <initializer_list>

#include <stdexcept>

class ConstStrBlobPtr;
class StrBlobPtr;
class StrBlob{
    friend class ConstStrBlobPtr;
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);
public:
    using size_type = std::vector<std::string>::size_type;
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(std::make_shared<std::vector<std::string> >()){ }
    StrBlob(std::initializer_list<std::string> il):
            data(std::make_shared<std::vector<std::string> >(il)){ }

    //copy constructor
    StrBlob(const StrBlob &orig):
            data(std::make_shared<std::vector<std::string>>(*orig.data)) {}

    //copy-assignment operator
    StrBlob& operator=(const StrBlob &rhs){
        data = std::make_shared<std::vector<std::string>>(*rhs.data);
        return *this;
    }
    
    StrBlob(StrBlob&& rhs) noexcept : data(std::move(rhs.data)) {}
    StrBlob& operator=(StrBlob &&rhs) noexcept{
        if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
        }
        return *this;
    }
    std::string &operator[](size_t n){
        check(n, "out of range");
        return data->at(n);
    }
    const std::string &operator[](size_t n) const{
        check(n, "out of range");
        return data->at(n);
    }

    size_t size() const {
        return data->size();
    }
    bool empty() const{
        return data->empty();
    }

    void push_back(const std::string &str){
        data->push_back(str);
    }

    void push_back(std::string && s){
        data -> push_back(std::move(s));
    }

    void pop_back(){
        check(0,"pop_back on empty strBlob");
        data->pop_back();
    }

    std::string &front(){
        check(0,"front on empty strBlob");
        return data->front();
    }

    const std::string &front() const {
        check(0,"front on empty strBlob");
        return data->front();
    }

    std::string &back(){
        check(0,"back on empty strBlob");
        return data->back();
    }

    const std::string &back() const {
        check(0,"back on empty strBlob");
        return data->back();
    }

private:
    std::shared_ptr<std::vector<std::string> > data;
    void check(size_t i,const std::string& msg) const {
        if(i >= data->size()){
            throw std::out_of_range(msg);
        }
    }
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

class ConstStrBlobPtr{
    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    
public:
    ConstStrBlobPtr():curr(0) { }
    ConstStrBlobPtr(const StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) { }
    const std::string& operator*() const{
        auto p = check(curr, "derefrence past end.");
        return (*p)[curr];
    }
    const std::string* operator->() const{
        return & this->operator*();
    }
    const std::string& operator[](size_t n) const{
        auto p = check(n, "dereference out of range.");
        return (*p)[n];
    }

    ConstStrBlobPtr &operator++(){
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    ConstStrBlobPtr &operator--(){
        check(curr,"increment past end of StrBlobPtr");
        --curr;
        return *this;
    }
    ConstStrBlobPtr operator++(int){
        auto ret = *this;
        ++*this;
        return ret;
    }
    ConstStrBlobPtr operator--(int){
        auto ret = *this;
        --*this;
        return ret;
    }
    ConstStrBlobPtr &operator+=(size_t n){
        curr += n;
        check(curr, "increment past end of ConstStrBlobPtr");
        return *this;
    }
    ConstStrBlobPtr &operator-=(size_t n){
        curr -= n;
        check(curr, "increment past end of ConstStrBlobPtr");
        return *this;
    }
    ConstStrBlobPtr operator+(size_t n) const{
        ConstStrBlobPtr ret = *this;
        ret += n;
        return ret;
    }
    ConstStrBlobPtr operator-(size_t n) const{
        ConstStrBlobPtr ret = *this;
        ret -= n;
        return ret;
    }


    
private:
    std::shared_ptr<std::vector<std::string> >
        check(std::size_t i, const std::string &msg) const{
            auto ret = wptr.lock();
            if(!ret){
                throw std::runtime_error("unbound StrBlobstr");
            }
            if(i >= ret->size()){
                throw std::out_of_range(msg);
            }
            return ret;
        }
    std::size_t curr;
    std::weak_ptr<std::vector<std::string> > wptr;
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

class StrBlobPtr{
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) { }
    std::string& operator*()const{
        auto p = check(curr, "derefrence past end.");
        return (*p)[curr];
    }

    std::string* operator->()const{
        return & this->operator*();
    }

    std::string& operator[](size_t n){
        auto p = check(n, "dereference out of range.");
        return (*p)[n];
    }
    const std::string& operator[](size_t n) const{
        auto p = check(n, "dereference out of range.");
        return (*p)[n];
    }

    StrBlobPtr &operator++(){
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    StrBlobPtr &operator--(){
        check(curr, "increment past end of StrBlobPtr");
        --curr;
        return *this;
    }
    StrBlobPtr operator++(int){
        auto ret = *this;
        ++*this;
        return ret;
    }
    StrBlobPtr operator--(int){
        auto ret = *this;
        --*this;
        return ret;
    }
    StrBlobPtr &operator+=(size_t n){
        curr += n;
        check(curr, "increment past end of StrBlobPtr");
        return *this;
    }
    StrBlobPtr &operator-=(size_t n){
        curr -= n;
        check(curr, "increment past end of StrBlobPtr");
        return *this;
    }
    StrBlobPtr operator+(size_t n) const{
        StrBlobPtr ret = *this;
        ret -= n;
        return ret;
    }
    StrBlobPtr operator-(size_t n) const{
        StrBlobPtr ret = *this;
        ret -= n;
        return ret;
    }


    
private:
    std::shared_ptr<std::vector<std::string> >
        check(std::size_t i, const std::string &msg) const{
            auto ret = wptr.lock();
            if(!ret){
                throw std::runtime_error("unbound StrBlobstr");
            }
            if(i >= ret->size()){
                throw std::out_of_range(msg);
            }
            return ret;
        }
    std::size_t curr;
    std::weak_ptr<std::vector<std::string> > wptr;
};
bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

#endif