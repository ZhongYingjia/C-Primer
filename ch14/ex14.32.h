#ifndef EX14_32_H
#define EX14_32_H

class StrBlobPtr;

class StrBlobPtr_pointer{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr *p):pointer(p){}

    StrBlobPtr& operator*(){
        return *(this->pointer);
    }

    StrBlobPtr* operator->(){
        return & this->operator*();
    }

private:
    StrBlobPtr* pointer = nullptr;
};



#endif