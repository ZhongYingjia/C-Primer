#include "ex13.34.h"

int main()
{
    Message firstMail("hello, world!");
    Message secondMail("yingyingying");
    Folder myBox;

    firstMail.print_debug();
    firstMail.save(myBox);
    myBox.print_debug();

    secondMail.print_debug();
    secondMail.save(myBox);
    myBox.print_debug();

    firstMail = firstMail;
    firstMail.save(myBox);
    myBox.print_debug();

    return 0;
}