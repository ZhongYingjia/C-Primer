#include <cassert>
#include <iostream>
#include "uniquePtr.h"
#include "sharedPtr.h"
#include "DebugDelete.h"

struct Foo {
    Foo() { std::cout << "Foo()\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }
    Foo(const Foo&) { std::cout << "Foo copy ctor\n"; }
    Foo(Foo&&) { std::cout << "Foo move ctor\n"; }
};

struct Fooo {
    Fooo(int n = 0) noexcept : bar(n) { std::cout << "Fooo: constructor, bar = " << bar << '\n'; }
    ~Fooo() { std::cout << "Fooo: destructor, bar = " << bar << '\n'; }
    int GetBar() const noexcept { return bar; }

private:
    int bar;
};

struct D {
    void bar() { std::cout << "Call deleter D::bar()...\n"; }
    void operator()(Foo* p) const
    {
        std::cout << "Call delete from function object...\n";
        delete p;
    }
};

int main()
{
    std::cout << "SharedPtr constructor with no managed object\n";
    {
        sharedPtr<Foo> sh1;
    }

    std::cout << "SharedPtr constructor with object\n";
    {
        sharedPtr<Foo> sh2(new Foo);
        std::cout << sh2.use_count() << '\n';
        sharedPtr<Foo> sh3(sh2);
        std::cout << sh3.use_count() << '\n';
    }

    std::cout << "SharedPtr constructor with deleter\n";
    {
        sharedPtr<Foo> sh5(new Foo, [](Foo* p) {
            std::cout << "Call delete from lambda...\n";
            delete p;
        });
    }

    {
        sharedPtr<Fooo> sptr(new Fooo(1));
        std::cout << "The first Fooo's bar is " << sptr->GetBar() << "\n";
        sptr.reset(new Fooo);
        std::cout << "The second Fooo's bar is " << sptr->GetBar() << "\n";
    }

    {
        std::cout << "======================\nUniquePtr constructor:\n";
        uniquePtr<Foo> up1;
        uniquePtr<Foo> up1b(nullptr);
        uniquePtr<Foo> up2(new Foo);

        DebugDelete d;
        uniquePtr<Foo, DebugDelete> up3(new Foo, d);
        uniquePtr<Foo, DebugDelete&> up3b(new Foo, d);
        uniquePtr<Foo, DebugDelete> up4(new Foo, DebugDelete());
        uniquePtr<Foo> up5b(std::move(up2));
        uniquePtr<Foo, DebugDelete> up6b(std::move(up3));

        // uniquePtr<Foo> up7 = std::move(up5b);
        // Foo* fp = up7.release();
        // assert(up7.get() == nullptr);
        // delete fp;

        up6b.reset(new Foo());
        up6b.reset(nullptr);

        uniquePtr<Fooo> up71(new Fooo(1));
        uniquePtr<Fooo> up72(new Fooo(2));

        up71.swap(up72);

        std::cout << "up71->val:" << up71->GetBar() << std::endl;
        std::cout << "up72->val:" << (up72.get())->GetBar() << std::endl;

        uniquePtr<Foo, D> up8(new Foo(), D());
        D& del = up8.get_deleter();
        del.bar();
    }
}