#include "ex12.19.h"
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("../data/book.txt");
    if(!ifs) return -1;
    StrBlob sb;
    
    for(std::string str; std::getline(ifs, str);){
        sb.push_back(str);
    }
    for(StrBlobPtr pbeg(sb.begin()),pend(sb.end()); pbeg.isNotEqual(pend); pbeg.incr()){
        std::cout << pbeg.deref() <<std::endl;
    }

    return 0;

}