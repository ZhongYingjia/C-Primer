#include "QueryResult.h"
#include <iostream>
using std::ostream;

ostream &operator<<(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 1 ? "times" : "time" ) << std::endl;
    for(auto num : *qr.lines){
        os << "\t(line " << num + 1 <<") "
            << *(qr.file->begin() + num) <<std::endl;
    }
    return os;
}