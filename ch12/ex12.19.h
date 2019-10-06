#ifndef STRBlob19
#define STRBlob19

#include <memory>
#include <vector>
#include <string>

#include <stdexcept>

class StrBlobPtr;
class StrBlob{
    friend class StrBlobPtr;
    public:
        StrBlobPtr begin();
        StrBlobPtr end();
        using size_type = std::vector<std::string>::size_type; 
        StrBlob():data(std::make_shared<std::vector<std::string> >()){ }
        StrBlob(std::initializer_list<std::string> il):
                data(std::make_shared<std::vector<std::string> >(il)){ }
        size_t size() const {
            return data->size();
        }
        bool empty() const{
            return data->empty();
        }

        void push_back(const std::string &str){
            data->push_back(str);
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

class StrBlobPtr{
    public:
        StrBlobPtr():curr(0) { }
        StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) { }
        std::string& deref() const {
            auto p = check(curr, "derefrence past end.");
            return (*p)[curr];
        }
        StrBlobPtr& incr(){
            check(curr, "increment past end of StrBlobPtr");
            ++curr;
            return *this;
        }
        bool isNotEqual(StrBlobPtr& p) const {
            return this->curr != p.curr;
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

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this,data->size());
}


#endif