#include<string>
#include<array>
#include <iostream>

using std::string;
using std::array;

class Date{
    public:
        explicit Date(const string & date = "");
        void print();
        unsigned year = 1970;
        unsigned month = 1;
        unsigned day = 1;

    private:
        array<string,12>monthName{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        unsigned monthFromName(const string &month);

};

Date::Date(const string& date){
    if(date.empty()) return;
    string delimiters{" ,/"};
    auto monthDelimiter = date.find_first_of(delimiters);
    if(monthDelimiter == string::npos) throw std::invalid_argument("This format is not supported now.");
    month = monthFromName(date.substr(0,monthDelimiter));
    auto dayDelimiter = date.find_first_of(delimiters,monthDelimiter + 1);
    day = std::stoi(date.substr(monthDelimiter + 1,dayDelimiter - monthDelimiter + 1));
    year = std::stoi(date.substr(dayDelimiter+1));
}

void Date::print(){
    std::cout << year <<"-"<< month <<"-" << day << std::endl;
}

unsigned Date::monthFromName(const string &month){
    if(month.empty()) return 0;
    if(std::isdigit(month[0])) return stoi(month);
    for(decltype(monthName.size()) i = 0; i != 12; ++i ){
        if(month.find(monthName[i]) != string::npos) return i+1 ;
    }
    return 0;
}

int main()
{
    { //  default case
        auto date = Date();
        date.print();
    }
    { //  case 0: January 1, 1900
        auto date = Date("January 1, 1900");
        date.print();
    }
    { //  case 1: 1/1/1900
        auto date = Date("1/1/1900");
        date.print();
    }
    { //  case 2: Jan 1, 1900
        auto date = Date("Jan 1, 1900");
        date.print();
    }
    return 0;
}