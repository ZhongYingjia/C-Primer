#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
class Foo{
public:
    Foo sorted() &&
    {
        sort(data.begin(), data.end());
        std::cout << "&&" << std::endl;
        return *this;
    }
    Foo sorted() const &
    {
        std::cout << "const &" << std::endl;
        // Foo ret(*this);
        // return ret.sorted();//ex13.56

        return Foo(*this).sorted();//ex13.57

    }
private:
    vector<int> data;
};

int main()
{
    Foo().sorted();
    Foo f;
    f.sorted();

    return 0;
}