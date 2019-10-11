#include"Sales_data.h"
int main()
{
    // std::string strCp5("C++ Primer 5th");
    // Sales_data cp5 = strCp5;
    // std::cout << cp5 << std::endl;

    Sales_data cp5("C++ Primer 5th", 4, 106.5);
    std::cout << static_cast<std::string>(cp5) << std::endl;
    std::cout << static_cast<double>(cp5) << std::endl;
    return 0;
}