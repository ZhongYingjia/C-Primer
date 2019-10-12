#ifndef Limit_bulk_quote_H
#define Limit_bulk_quote_H

#include "Disc_quote.h"

class Limit_bulk_quote:Disc_quote{
public:
    Limit_bulk_quote() = default;
    Limit_bulk_quote(const std::string& book, double sales_price, 
                    size_t min, double disc, size_t max):
                    Disc_quote(book, sales_price, min, disc),max_qty(max){ }
    double net_price(size_t) const override;
    void debug() const override;
private:
    size_t max_qty = 0;
};

inline
double Limit_bulk_quote::net_price(size_t n) const {
    if(n > max_qty) return max_qty * (1 - discount) * price + (n - max_qty) * price;
    else if(n >= quantity) return n * (1 - discount) * price;
    else return n * price;
}

inline
void Limit_bulk_quote::debug() const {
    Disc_quote::debug();
    std::cout << "\tmax_qty: " << max_qty << std::endl;
}


#endif