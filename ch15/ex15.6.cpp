#include "Bulk_quote.h"
#include "Quote.h"
#include <iostream>

double print_total(std::ostream&, const Quote&, size_t);

int main()
{
    Quote basic("testbook", 10.6);
    Bulk_quote bulk("testbook", 10.6, 10, 0.3);
    print_total(std::cout, basic, 12);
    print_total(std::cout, bulk, 12);

    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: "
        << ret <<std::endl; 
    return ret;
}