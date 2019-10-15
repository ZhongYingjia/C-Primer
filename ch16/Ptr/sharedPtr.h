#ifndef sharedPtr_H
#define sharedPtr_H

template <typename T>
class sharedPtr{
    using DelFuncPtr = void (*)(T*);
public:
    sharedPtr(T *ptr = nullptr, DelFuncPtr del = nullptr):
        ptr_(ptr), count_ptr_(new size_t(ptr != nullptr)), del_(del)
        { }
    
    ~sharedPtr()
    {
        if(!ptr_) return;
        if(--*count_ptr_ == 0){
            del_ ? del_(ptr_) : delete ptr_;
            delete count_ptr_;
        }
        ptr_ = nullptr;
        count_ptr_ = nullptr;
    }

    sharedPtr(const sharedPtr& sp): 
        ptr_(sp.ptr_), count_ptr_(sp.count_ptr_), del_(sp.del_){
            ++*count_ptr_;
        }

    sharedPtr& operator=(sharedPtr sp){
        swap(sp);
        return *this;
    }

    sharedPtr(sharedPtr &&sp) noexcept:
        sharedPtr() { swap(sp); }

    void reset(T* ptr = nullptr, DelFuncPtr del = nullptr){
        sharedPtr tmp(ptr, del);
        swap(tmp);
    }

    void swap(sharedPtr& r) noexcept{
        using std::swap;
        swap(ptr_, r.ptr_);
        swap(count_ptr_, r.count_ptr_);
        swap(del_, r.del_);
    }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *get(); }
    T* operator->() const noexcept { return get(); }
    std::size_t use_count() const noexcept { return *count_ptr_; }

    explicit operator bool() const noexcept { return ptr_ != nullptr; }
private:
    T* ptr_ = nullptr;
    std::size_t* count_ptr_ = nullptr;
    DelFuncPtr del_ = nullptr;
};



#endif