// g++ -std=c++17 -o container container.cpp && ./container

#include <iostream>
#include <algorithm>
#include <sstream>

class Vector
{
private:
    double *elem; // elem points to an array of sz doubles
    int sz;

public:
    Vector(int s) : elem{new double[s]}, sz{s} // constructor: acquire resources
    {
        for (int i = 0; i != s; ++i)
            elem[i] = 0; // initialize elements
    };
    Vector(std::initializer_list<double>); // initialize with a list
    Vector() : elem{nullptr}, sz{0} {};    // default constructor
    void push_back(double);                // add element at end increasing the size by one
    ~Vector() { delete[] elem; }           // destructor: release resources
    double &operator[](int i);
    int size() const;
};

void fct(int n)
{
    Vector v(n);
    // ... use v ...
    v[n - 1] = 7; // range check
    std::cout << "v[" << n - 1 << "] == " << v[n - 1] << std::endl;
    {
        Vector v2(2 * n);
        // ... use v and v2 ...
        v2[n - 1] = 8; // range check
        std::cout << "v2[" << n - 1 << "] == " << v2[n - 1] << std::endl;
    } // v2 is destroyed here
    // ... use v ..
} // v is destroyed here

Vector read(std::istream &is)
{
    Vector v;
    for (double d; is >> d;) // read floating-point values into d
        v.push_back(d);      // add d to v
    return v;
}

void Vector::push_back(double d)
{
    // allocate a new array
    double *p = new double[sz + 1];

    for (int i = 0; i != sz; ++i)
        p[i] = elem[i]; // copy old elements
    p[sz] = d;          // add d at the end
    delete[] elem;      // deallocate old array
    elem = p;           // make elem point to the new array
    ++sz;               // increase the size by one
}

double &Vector::operator[](int i) { return elem[i]; }
int Vector::size() const { return sz; }

Vector::Vector(std::initializer_list<double> lst) // initialize with a list
    : elem{new double[lst.size()]}, sz{(int)lst.size()}
{
    std::copy(lst.begin(), lst.end(), elem); // copy from lst into elem
}

int main(void)
{
    Vector v1 = {1, 2, 3, 4, 5};      // v1 has 5 elements
    Vector v2 = {1.23, 3.45, 6.7, 8}; // v2 has 4 elements

    fct(3);

    // make a input stream of 10 numbers
    std::istringstream iss("1 2 3 4 5 6 7 8 9 10");

    Vector v3 = read(iss);

    std::cout << "v3 has " << v3.size() << " elements" << std::endl;

    return 0;
}