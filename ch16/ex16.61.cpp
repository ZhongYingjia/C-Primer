#include <memory>
#include <utility>
#include <string>

template <typename T, typename... Args>
auto makeShared(Args&&... args)->std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main(int argc, char const *argv[])
{
    auto p = makeShared<std::string>(10, 'k');
    return 0;
}
