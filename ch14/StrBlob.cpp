#include "StrBlob.h"
#include <algorithm>

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), 
                                    rhs.data->begin(),rhs.data->end());
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs > rhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}




bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}
bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return lhs.curr <= rhs.curr;
}
bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return lhs.curr >= rhs.curr;
}



bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& x, const StrBlobPtr& y)
{
    return x.curr < y.curr;
}
bool operator>(const StrBlobPtr& x, const StrBlobPtr& y)
{
    return x.curr > y.curr;
}
bool operator<=(const StrBlobPtr& x, const StrBlobPtr& y)
{
    return x.curr <= y.curr;
}

bool operator>=(const StrBlobPtr& x, const StrBlobPtr& y)
{
    return x.curr >= y.curr;
}


StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this,data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const{
    return ConstStrBlobPtr(*this,data->size());
}
