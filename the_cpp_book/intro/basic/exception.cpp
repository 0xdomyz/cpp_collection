// g++ -std=c++17 -o exception exception.cpp && ./exception

#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(int s);
    double &operator[](int i);
    int size();

private:
    int sz;
    double *elem;
};

Vector::Vector(int s) : sz{s}, elem{new double[s]}
{
    for (int i = 0; i < s; i++)
        elem[i] = 0;
}

int Vector::size()
{
    return sz;
}

double &Vector::operator[](int i)
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

void f(Vector &v)
{
    // ...
    try
    {                    // exceptions here are handled by the handler defined below
        v[v.size()] = 7; // tr y to access beyond the end of v
    }
    catch (out_of_range)
    {
        cerr << "out of range error\n";
    }
    // ...
}

int main()
{
    Vector v(5);
    f(v);
}