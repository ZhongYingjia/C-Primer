#include <iostream>
#include "Sales_data.h"

using std::istream;
using std::ostream;


Sales_data& Sales_data::combine(const Sales_data & rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream& is,Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os,const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " 
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data& rhs1,const Sales_data &rhs2)
{
    Sales_data sum = rhs1;
    sum.combine(rhs2);
    return sum;
}


