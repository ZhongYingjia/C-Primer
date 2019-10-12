#ifndef Quote_H
#define Quote_H

#include <string>
#include <iostream>
#include <utility>
class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price){ }
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote&&) = default;
    virtual ~Quote() = default;


    std::string isbn() const{ return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const ;

    virtual Quote* clone() const & { return new Quote(*this);  }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
    
    
private:
    std::string bookNo;
protected:
    double price = 0.0;

};

inline
void Quote::debug() const{
    std::cout << "data members: \n" << "\tbookNo: " << bookNo << "\tprice: " << price << std::endl;
}

double print_total(std::ostream& os, Quote const& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

#endif