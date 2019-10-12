#ifndef Bulk_quote_H
#define Bulk_quote_H

#include "Disc_quote.h"
class Bulk_quote: public Disc_quote{
public:
    // Bulk_quote() = default;
    // Bulk_quote(const std::string& book, double sales_price, 
    //             size_t qty, double disc):
    //             Disc_quote(book, sales_price, qty, disc){ }
    using Disc_quote::Disc_quote;
    double net_price(size_t) const override;
    void debug() const override;
    Bulk_quote* clone() const & override{ return new Bulk_quote(*this); }
    Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
};

inline
double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= quantity){
        return cnt * (1 - discount) * price;
    }
    else{
        return cnt * price;
    }
}

inline
void Bulk_quote::debug() const {
    Quote::debug();
    std::cout << "\tminqty: " << quantity << "\tdiscount: " << discount << std::endl;
}


#endif