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
    // *x.p = 4;         // oops: write to deallocated memory
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
    int data;

public:
    Representation() : data{0} {}
    Representation(int d) : data{d} {}
    friend ostream &operator<<(ostream &os, const Representation &rep)
    {
        os << "Representation: " << rep.data;
        return os;
    }
};

class Image
{
public:
    Image(int d) : rep{new Representation{d}}, shared{false} {}
    // ...
    Image(const Image &a); // copy constr uctor
    // ...
    void write_block(Descriptor);
    // ...
    // cout representation
    friend ostream &operator<<(ostream &os, const Image &img)
    {
        os << img.rep;
        return os;
    }

private:
    Representation *clone()
    {
        return new Representation{*rep};
    }; // copy *rep
    Representation *rep;
    bool shared;
};

Image::Image(const Image &a) // do shallow copy and prepare for copy-on-wr ite
    : rep{a.rep},
      shared{true}
{
}

void Image::write_block(Descriptor d)
{
    if (shared)
    {
        rep = clone();  // make a copy of *rep
        shared = false; // no more sharing
    }
    // ... now we can safely write to our own copy of rep ...
}

int main(void)
{
    Image img1{1};
    cout << "img1: " << img1 << endl;
    Image img2{img1};
    cout << "img2: " << img2 << endl;
    img2.write_block(Descriptor{});
    cout << "img2: " << img2 << endl;

    return 0;
}