// Compile and run: g++ unique_ptr.cpp -o unique_ptr && ./unique_ptr

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct X
{
    X() { cout << "X()" << endl; }
    X(int) { cout << "X(int)" << endl; }
    ~X() { cout << "~X()" << endl; }
    void do_something() { cout << "X::do_something()" << endl; }
};

// define a functor that throws an exception
class Z
{
    void f() { throw 1; }
};

void f(int i, int j) // X* vs. unique_ptr<X>
{
    X *p = new X;            // allocate a new X
    unique_ptr<X> sp{new X}; // allocate a new X and give its pointer to unique_ptr
    // ..
    if (i < 99)
        throw Z{}; // may throw an exception
    if (j < 77)
        return;         // may retur n "ear ly"
    p->do_something();  // may throw an exception
    sp->do_something(); // may throw an exception
    // ...
    delete p; // destroy *p
}
void f2(int i, int j) // use a local var iable
{
    X x;
    // ...
}

unique_ptr<X> make_X(int i)
// make an X and immediately give it to a unique_ptr
{
    // ... check i, etc. ...
    return unique_ptr<X>{new X{i}};
}

int main(void)
{
    f(100, 100);
    f2(100, 100);
    auto p = make_X(2);
    p->do_something();
    return 0;
}