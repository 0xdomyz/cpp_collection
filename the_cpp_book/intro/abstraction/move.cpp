// g++ -std=c++11 -o move move.cpp && ./move

#include <iostream>

using namespace std;

class Vector
{
private:
    double *elem; // elem points to an array of sz doubles
    int sz;

public:
    Vector(int s)
    {
        elem = new double[s];
        sz = s;
    };                                  // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; }        // destructor: release resources
    Vector(const Vector &a);            // copy constr uctor
    Vector &operator=(const Vector &a); // copy assignment
    double &operator[](int i) { return elem[i]; };
    const double &operator[](int i) const { return elem[i]; };
    int size() const { return sz; };
    Vector(Vector &&a);            // move constr uctor
    Vector &operator=(Vector &&a); // move assignment
};

Vector::Vector(const Vector &a) // copy constructor
    : elem{new double[a.sz]},   // allocate space for elements
      sz{a.sz}
{
    for (int i = 0; i != sz; ++i) // copy elements
        elem[i] = a.elem[i];
}

Vector &Vector::operator=(const Vector &a) // copy assignment
{
    double *p = new double[a.sz];
    for (int i = 0; i != a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem; // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}

Vector::Vector(Vector &&a)
    : elem{a.elem}, // "grab the elements" from a
      sz{a.sz}
{
    a.elem = nullptr; // now a has no elements
    a.sz = 0;
}

Vector &Vector::operator=(Vector &&a)
{
    delete[] elem; // deallocate old space
    elem = a.elem; // "grab the elements" from a
    sz = a.sz;
    a.elem = nullptr; // now a has no elements
    a.sz = 0;
    return *this;
}

int main()
{
    // move vector
    Vector v(2);
    v[0] = 1.0;
    v[1] = 2.0;

    cout << "v.size() = " << v.size() << endl;

    cout << "move constructor" << endl;
    Vector vv = move(v);

    cout << "move assignment" << endl;
    Vector vvv(2);
    vvv = move(vv);

    cout << "v.size() = " << v.size() << endl;
    cout << "vv.size() = " << vv.size() << endl;
    cout << "vvv.size() = " << vvv.size() << endl;

    return 0;
}