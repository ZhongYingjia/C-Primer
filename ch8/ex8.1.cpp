#include <iostream>
#include <string>
using std::istream;

using std::string;

istream& func(istream& istrm)
{
    string word;
    while( istrm >> word ){
        std::cout << word <<std::endl;
    }
    istrm.clear();
    return istrm;
}

int main()
{
    istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    system("pause");
    return 0;

}



