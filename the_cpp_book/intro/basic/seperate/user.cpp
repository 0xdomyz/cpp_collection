// complie user.cpp and Vector.cpp and Vector.h, link them together:
// g++ -c user.cpp Vector.cpp
// g++ user.o Vector.o -o user
// run the executable:
// ./user

#include "Vector.h" // get Vector’s interface
#include <cmath>    // get the the standard-librar y math function interface including sqrt()
#include <iostream> // get the standard-librar y input/output interface

using namespace std; // make std members visible (§2.4.2)

double sqrt_sum(Vector &v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
        sum += sqrt(v[i]); // sum of square roots
    return sum;
}

int main()
{
    Vector v(4);
    for (int i = 0; i != v.size(); ++i)
        v[i] = i; // v[i] is the element of v at index i
    cout << "sum of square roots: " << sqrt_sum(v) << "\n";
}
