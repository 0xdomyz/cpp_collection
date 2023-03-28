// Compile and run: g++ calling_constructors_and_destructors.cpp -o calling_constructors_and_destructors && ./calling_constructors_and_destructors

#include <iostream>
#include <stdlib.h>

using namespace std;

struct X
{
    int i;
    X(int ii) : i{ii} {}
    X() : i{0} {}
    ~X() {}
};

class C
{
    X *p;
    int sz;
    int space;

public:
    C() : p{nullptr}, sz{0}, space{0} {}
    C(int n) : p{new X[n]}, sz{n}, space{n} {}
    ~C() { delete[] p; }
    C(const C &);            // copy constructor
    C &operator=(const C &); // copy assignment
    C(C &&);                 // move constructor
    C &operator=(C &&);      // move assignment
    int size() const { return sz; }
    int capacity() const { return space; }
    void push_back(const X &a);
    void pop_back();
};

void C::push_back(const X &a)
{
    // ...
    // new (p) X{a}; // copy constr uct an X with the value a in address p
    // ...
}

void C::pop_back()
{
    // ...
    p->~X(); // destroy the X in address p
}

class Nonlocal
{
public:
    // ...
    Nonlocal() {}
    // allow new to be used
    void *operator new(size_t) { return ::new Nonlocal; }
    void destroy() { this->~Nonlocal(); } // explicit destruction
private:
    // ...
    ~Nonlocal(); // don’t destroy implicitly
};
void user()
{
    // Nonlocal x;          // error : cannot destroy a Nonlocal
    X *p = new Nonlocal; // OK
    // ...
    // delete p;    // error : cannot destroy a Nonlocal
    p.destroy(); // OK
}

int main(void)
{
    return 0;
}
