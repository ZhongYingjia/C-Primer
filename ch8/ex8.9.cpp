#include <iostream>
#include <string>
#include <sstream>
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
    std::istringstream iss("test");
    func(iss);
    system("pause");
    return 0;

}



