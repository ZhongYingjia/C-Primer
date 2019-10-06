#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
    //12.10
    // std::shared_ptr<int> p(new int(42));
    // process(std::shared_ptr<int>(p));

    // /**
    //   * codes below shows how the reference count change.
    //   */
    // std::cout << p.use_count() << "\n";
    // auto q = p;
    // std::cout << p.use_count() << "\n";
    // std::cout << "the int p now points to is:" << *p << "\n";

    //12.11
    // std::shared_ptr<int> p(new int(42));

    // /**
    //  * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr
    //  * and copy it
    //  *          to the parameter.However it is not a copy of p. As a result, at
    //  * end of this
    //  *          main function p will free the memory that has been freed inside
    //  * process ().
    //  *          That's why "double freed or corruption" was generated.
    //  */
    // process(std::shared_ptr<int>(p.get()));

    //12.13
    {
        auto sp = std::make_shared<int>();
        auto p = sp.get();
        delete p;
    }


    


    return 0;
}