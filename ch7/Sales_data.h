#ifndef S
#define S
#include <string>
#include <iostream>

class Sales_data;
std::istream& read(std::istream &is,Sales_data&);
std::ostream& print(std::ostream &os,const Sales_data&);
Sales_data add(const Sales_data& rhs1,const Sales_data &rhs2);

class Sales_data{
    friend std::istream& read(std::istream &is,Sales_data&);
    friend std::ostream& print(std::ostream &os,const Sales_data&);
    friend Sales_data add(const Sales_data& rhs1,const Sales_data &rhs2);

    public:
        Sales_data(const std::string &s, unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n)
        {
            //std::cout << " Sales_data(const std::string &s, unsigned n,double p) " <<std::endl;
        }
        Sales_data():Sales_data("",0,0)
        {
            //std::cout << " Sales_data() " <<std::endl;
        }
        Sales_data(const std::string &s):Sales_data(s,0,0)
        {
            //std::cout << " Sales_data(const std::string &s) " <<std::endl;
        }
        
        Sales_data(std::istream& is):Sales_data(){
            read(is, *this);
        }

        std::string isbn()const{return bookNo;}
        Sales_data& combine(const Sales_data &);
    
    private:
        double avg_price() const{return units_sold? revenue/units_sold:0;}

        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
#endif