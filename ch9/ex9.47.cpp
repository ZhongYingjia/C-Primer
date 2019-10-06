#include <string>
#include <iostream>

using std::string;

int main()
{
	string str("ab2c3d7R4E6");
    string digits("0123456789");
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    //v1
    
    for(string::size_type pos = 0; (pos = str.find_first_of(digits,pos)) != string::npos; ++pos){
        std::cout << str[pos] << " ";
    }
    std::cout << "digits" <<std::endl;

    for(string::size_type pos = 0; (pos = str.find_first_of(alphabet,pos)) != string::npos; ++pos){
        std::cout << str[pos] << " ";
    }
    std::cout << "alphabet" <<std::endl;
     
    //v2
    for(string::size_type pos = 0; (pos = str.find_first_not_of(alphabet,pos)) != string::npos; ++pos){
        std::cout << str[pos] << " ";
    }
    std::cout << "digits" <<std::endl;

    for(string::size_type pos = 0; (pos = str.find_first_not_of(digits,pos)) != string::npos; ++pos){
        std::cout << str[pos] << " ";
    }
    std::cout << "alphabet" <<std::endl;


    return 0;
}