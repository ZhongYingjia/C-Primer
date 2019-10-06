#ifndef STRBlob
#define STRBlob

#include <memory>
#include <vector>
#include <string>

#include <stdexcept>

class StrBlob{
    public:
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



#endif