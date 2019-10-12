#ifndef Disc_quote_H
#define Disc_quote_H

#include "Quote.h"

class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double sales_price, 
            size_t qty, double disc):
            Quote(book, sales_price), quantity(qty), discount(disc){ }
    double net_price(size_t) const = 0;
    void debug() const override;
 
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

inline
void Disc_quote::debug() const {
    Quote::debug();
    std::cout << "\tminqty: " << quantity << "\tdiscount: " << discount << std::endl;
}


#endif