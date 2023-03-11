// g++ -std=c++11 -o copy copy.cpp && ./copy

#include <complex>
// complex is a class template
// class template is a template that defines a class
// class <double> is a class template instantiation
// class instantiation is a class that is created from a class template
#include <iostream>

using namespace std;

// function to copy a complex number
complex<double> copy(complex<double> z)
{
    complex<double> zz = z; // copy initialization
    complex<double> zzz;
    zzz = z; // copy assignment
    return z;
}

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

int main()
{
    // copy
    complex<double> z = 1.0 + 2.0i;
    complex<double> zz = copy(z);
    cout << "z = " << z << ", zz = " << zz << endl;

    // copy vector
    Vector v(2);
    v[0] = 1.0;
    v[1] = 2.0;

    cout << "copy constructor" << endl;
    Vector vv = v; // copy constructor

    cout << "copy assignment" << endl;
    Vector vvv(2);
    vvv = v; // copy assignment

    cout << "v = " << v[0] << ", " << v[1] << endl;
    cout << "vv = " << vv[0] << ", " << vv[1] << endl;
    cout << "vvv = " << vvv[0] << ", " << vvv[1] << endl;

    // change v
    cout << "change v" << endl;
    v[0] = 3.0;

    cout << "v = " << v[0] << ", " << v[1] << endl;
    cout << "vv = " << vv[0] << ", " << vv[1] << endl;
    cout << "vvv = " << vvv[0] << ", " << vvv[1] << endl;

    return 0;
}