#include "ex14.15.h"

int main()
{
    Book book1(123, "CP5", "Lippman", "2012",2);
    Book book2(123, "CP5", "Lippman", "2012",4);

    std::cout << book1 + book2 << std::endl;

    return 0;
}
