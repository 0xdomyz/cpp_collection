// Compile and run: g++ meaning_of_copy.cpp -o meaning_of_copy && ./meaning_of_copy

#include <iostream>
#include <memory>

using namespace std;

struct S
{
    int *p; // a pointer
};
S x{new int{0}};

void f()
{
    S y{x};           // ‘‘copy’’ x
    *y.p = 1;         // change y; affects x
    *x.p = 2;         // change x; affects y
    delete y.p;       // affects x and y
    y.p = new int{3}; // OK: change y; does not affect x
    *x.p = 4;         // oops: write to deallocated memory
};

struct S2
{
    shared_ptr<int> p;
};
// S2 x{new int{0}};

void f2()
{
    S2 x{make_shared<int>(0)};
    S2 y{x};               // ‘‘copy’’ x
    *y.p = 1;              // change y, affects x
    *x.p = 2;              // change x; affects y
    y.p.reset(new int{3}); // change y; affects x
    *x.p = 4;              // change x; affects y
};

class Descriptor
{
};

class Representation
{
public:
    // ...
    virtual Representation *clone() = 0;
    // ...
    virtual void write_block(Descriptor) = 0;
    // ...
};

class Image
{
public:
    // ...
    Image(const Image &a); // copy constr uctor
    // ...
    void write_block(Descriptor);
    // ...
private:
    Representation *clone(); // copy *rep
    Representation *rep;
    bool shared;
};

Image::Image(const Image &a) // do shallow copy and prepare for copy-on-wr ite
    : rep{a.rep},
      shared{true}
{
}

bool shared; // true if *rep is shared

void write_block(Descriptor d)
{
    if (shared)
    {
        // rep = clone();  // make a copy of *rep
        shared = false; // no more sharing
    }
    // ... now we can safely write to our own copy of rep ...
}

int main(void) {}