#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;


int main()
{
    vector<string> vs{"12","4.5","33"};
    int iResult = 0;
    for(auto i :vs){
        iResult += std::stoi(i);
    }
    double dResult = 0.0;
    for(auto i: vs){
        dResult += std::stod(i);
    }

    std::cout << "int:" << iResult<<std::endl;
    std::cout << "double:" << dResult<<std::endl;




	

    return 0;
    
}