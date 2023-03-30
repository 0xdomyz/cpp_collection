// Compile and run: g++ deleted_functions.cpp -o deleted_functions && ./deleted_functions

#include <iostream>

using namespace std;

class Base
{
    // ...
public:
    Base &operator=(const Base &) = delete; // disallow copying
    Base(const Base &) = delete;
    Base &operator=(Base &&) = delete; // disallow moving
    Base(Base &&) = delete;
    Base(){};
};
Base x1;
// Base x2{x1}; // error : no copy constr ucto

template <class T>
T *clone(T *p) // return copy of *p
{
    return new T{*p};
};

class Shape
{
    // ...
};

class Foo
{
    // ...
};

// Foo *clone(Foo *) = delete; // don’t try to clone a Foo
void f(Shape *ps, Foo *pf)
{
    Shape *ps2 = clone(ps); // fine
    // Foo *pf2 = clone(pf);   // error : clone(Foo*) deleted
}

struct Z
{
    // ...
    Z(double){};     // can initialize with a double
    Z(int) = delete; // but not with an integer
};

void f2()
{
    // Z z1{1};   // error : Z(int) deleted
    Z z2{1.0}; // OK
}

class Not_on_stack
{
    // ...
    ~Not_on_stack() = delete;
};

class Not_on_free_store
{
    // ...
    void *operator new(size_t) = delete;
};

void f3()
{
    // Not_on_stack v1;                               // error : can’t destroy
    Not_on_free_store v2;                // OK
    Not_on_stack *p1 = new Not_on_stack; // OK
    // Not_on_free_store *p2 = new Not_on_free_store; // error : can’t allocate
}

int main(void)
{
    return 0;
}
