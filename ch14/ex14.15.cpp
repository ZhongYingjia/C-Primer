#include "ex14.15.h"

Book& Book::operator+=(const Book &rhs)
{
    if(*this == rhs){
        number_ += rhs.number_;
    }
    return *this;
}
std::istream &operator>>(std::istream &is, Book &b)
{
    is >> b.No_ >> b.name_ >> b.author_ >> b.pubdate_  >> b.number_;
    if(!is) b = Book();
    return is;
}
std::ostream &operator<<(std::ostream &os, const Book &b)
{
    os << b.No_ << " " << b.name_ << " " << b.author_<< " " << b.pubdate_<< " " << b.number_;
    return os;
}
bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.No_ == rhs.No_;
}
bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const Book &lhs, const Book &rhs)
{
    return lhs.number_ > rhs.number_;
}
bool operator<(const Book &lhs, const Book &rhs)
{
    return rhs > lhs;
}
Book operator+(const Book &lhs, const Book &rhs)
{
    Book sum = lhs;
    sum += rhs;
    return sum;
}



