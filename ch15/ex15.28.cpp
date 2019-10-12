#include "Bulk_quote.h"
#include <vector>
using std::vector;

#include<iostream>
#include<memory>


int main()
{
    //28

    {
        vector<Quote> basket;
        basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
        std::cout << basket.back().net_price(15) << std::endl;
    }

    //29
    {
        vector<std::shared_ptr<Quote>> basket;
        basket.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
        std::cout << basket.back()->net_price(15) << std::endl;
    }
    return 0;
}