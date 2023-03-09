// g++ -o mod mod.cpp && ./mod

#include <iostream>

double sqrt(double);

class Vector
{
public:
    Vector(int s);
    double &operator[](int i);
    int size();

private:
    double *elem; // elem points to an array of sz doubles
    int sz;
};

// A function that returns the square root of n using Babylonian method
double sqrt(double n)
{
    // Start with an initial guess
    double x = n;
    // Loop until the difference between x and n/x is very small
    while (std::abs(x - n / x) > 0.00000001) // abs is from <cmath>
    {
        // Update x by taking the average of x and n/x
        x = (x + n / x) / 2;
    }
    // Return the final value of x
    return x;
}

Vector::Vector(int s)            // definition of the constructor
    : elem{new double[s]}, sz{s} // initialize members
{
}

double &Vector::operator[](int i) // definition of subscripting
{
    return elem[i];
}
int Vector::size() // definition of size()
{
    return sz;
}

int main(void)
{
    Vector v(3);
    v[0] = 2;
    v[1] = 3;
    v[2] = 4;
    std::cout << "v[0] = " << v[0] << std::endl;
    std::cout << "v[1] = " << v[1] << std::endl;
    std::cout << "v[2] = " << v[2] << std::endl;
    std::cout << "v.size() = " << v.size() << std::endl;

    // display with 4 digits after the decimal point
    std::cout.precision(4);
    std::cout << "sqrt(2) = " << sqrt(2) << std::endl;
    std::cout << "sqrt(3) = " << sqrt(3) << std::endl;
    std::cout << "sqrt(4) = " << sqrt(4) << std::endl;
    // turn back to default
    std::cout.precision(6);
    return 0;
}