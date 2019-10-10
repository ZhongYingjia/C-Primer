#ifndef Sales_data_H
#define Sales_data_H
#include <string>
#include <iostream>


class Sales_data;
std::istream& operator>>(std::istream &is,Sales_data&);
std::ostream& operator<<(std::ostream &os,const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

class Sales_data{
    friend std::istream& operator>>(std::istream &is,Sales_data&);
    friend std::ostream& operator<<(std::ostream &os,const Sales_data&);

public:
    Sales_data(const std::string &s, unsigned n,double p):
        bookNo(s),units_sold(n),revenue(p*n) { }
    Sales_data():Sales_data("",0,0){ }
    Sales_data(const std::string &s):Sales_data(s,0,0){ }
    Sales_data(std::istream& is): Sales_data() { is>>*this; }


    std::string isbn()const{ return bookNo; }
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const std::string&);


private:
    double avg_price() const{return units_sold? revenue/units_sold:0;}

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif