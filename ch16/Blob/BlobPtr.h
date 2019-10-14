#ifndef BlobPtr_H
#define BlobPtr_H
#include "Blob.h"
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>


template <typename> class BlobPtr;
template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> 
class BlobPtr{
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0):
        wptr(a.data), curr(sz){ }
    T& operator*() const{
        auto p = check(curr, "derefenrence past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const ;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};
template<typename T> std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if(!ret) throw std::runtime_error("unbound Blob<T>Ptr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}


template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++(){
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--(){
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int){
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    if (lhs.wptr.lock() != rhs.wptr.lock())
	{
		throw std::runtime_error("ptrs to different Blobs!");
	}
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs){
    if (lhs.wptr.lock() != rhs.wptr.lock())
	{
		throw std::runtime_error("ptrs to different Blobs!");
	}
    return !(lhs == rhs);
}

#endif