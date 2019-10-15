#ifndef uniquePtr_H
#define uniquePtr_H

struct Delete{
    template<typename T>
    void operator()(T* ptr) const {
        delete ptr;
    }
};

template <typename T, typename D = Delete>
class uniquePtr{
public:
    uniquePtr(T* ptr = nullptr, const D& d = D()) noexcept:
        ptr_(ptr), deleter_(d){ }
    ~uniquePtr() { deleter_(ptr_); }

    uniquePtr(const uniquePtr&) = delete;
    uniquePtr& operator=(const uniquePtr&) = delete;

    uniquePtr(uniquePtr&& other) noexcept:
        ptr_(other.ptr_), deleter_(std::move(other.deleter_))
        { other.ptr_ = nullptr; }

    uniquePtr& operator=(uniquePtr&& other) noexcept
    {
        if( this != &other){
            reset();
            ptr_ = other.ptr_;
            deleter_ = std::move(other.deleter_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    uniquePtr& operator=(std::nullptr_t) noexcept{
        reset();
        return *this;
    }

    void reset(T* q = nullptr) noexcept
    {
        deleter_(q);
        ptr_ = q;
    }

    void swap(uniquePtr& other) noexcept
    {
        using std::swap;
        swap(ptr_, other.ptr_);
        swap(deleter_, other.deleter_);
    }

    T* get() const { return ptr_; }
    D& get_deleter() noexcept { return deleter_; }
    explicit operator bool(){ return ptr_ != nullptr; }
    T& operator*() { return *get(); }
    T* operator->() { return get(); }
    T& operator[](std::size_t i) const { return ptr_[i]; }

private:
    T* ptr_ = nullptr;
    D deleter_;
};


#endif