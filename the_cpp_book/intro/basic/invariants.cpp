// g++ -std=c++11 -o invariants invariants.cpp && ./invariants

#include <stdexcept>
#include <iostream>

using namespace std;

class Vector
{
    int sz;
    double *elem;

public:
    Vector(int s);
    ~Vector() { delete[] elem; }
    double &operator[](int i) { return elem[i]; }
    int size() { return sz; }
};

Vector::Vector(int s)
{
    if (s < 0)
        throw length_error{"Vector::Vector"};
    elem = new double[s];
    sz = s;
}

void test()
{
    try
    {
        Vector v(-27);
    }
    catch (std::length_error)
    {
        // handle negative size
        cout << "Negative size" << endl;
    }
    catch (std::bad_alloc)
    {
        // handle memory exhaustion
        cout << "Memory exhaustion" << endl;
    }
}

int main()
{
    test();
}