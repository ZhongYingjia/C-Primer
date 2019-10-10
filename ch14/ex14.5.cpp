#include "ex14.5.h"

std::istream &operator>>(std::istream &is, Book &b)
{
    is >> b.No_ >> b.name_ >> b.author_ >> b.pubdate_;
    if(!is) b = Book();
    return is;
}
std::ostream &operator<<(std::ostream &os, const Book &b)
{
    os << b.No_ << " " << b.name_ << " " << b.author_<< " " << b.pubdate_;
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
