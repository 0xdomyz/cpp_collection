// g++ std_math.cpp -o std_math && ./std_math

#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

// standard math functions
void g(void)
{
    // abs(x) Absolute value
    // ceil(x) Smallest integer >= x
    // floor(x) Largest integer <= x
    // sqrt(x) Square root; x must be non-negative
    // cos(x) Cosine
    // sin(x) Sine
    // tan(x) Tangent
    // acos(x) Arccosine; the result is non-negative
    // asin(x) Arcsine; the result nearest to 0 is returned
    // atan(x) Arctangent
    // sinh(x) Hyperbolic sine
    // cosh(x) Hyperbolic cosine
    // tanh(x) Hyperbolic tangent
    // exp(x) Base e exponential
    // log(x) Natural logarithm, base e; x must be positive
    // log10(x) Base 10 logarith

    cout << "abs(-1) = " << abs(-1) << endl;
    cout << "ceil(1.1) = " << ceil(1.1) << endl;
    cout << "floor(1.1) = " << floor(1.1) << endl;
    cout << "sqrt(4) = " << sqrt(4) << endl;
    cout << "cos(0) = " << cos(0) << endl;
    cout << "sin(0) = " << sin(0) << endl;
    cout << "tan(0) = " << tan(0) << endl;
    cout << "acos(0) = " << acos(0) << endl;
    cout << "asin(0) = " << asin(0) << endl;
    cout << "atan(0) = " << atan(0) << endl;
    cout << "sinh(0) = " << sinh(0) << endl;
    cout << "cosh(0) = " << cosh(0) << endl;
    cout << "tanh(0) = " << tanh(0) << endl;
    cout << "exp(1) = " << exp(1) << endl;
    cout << "log(4) = " << log(4) << endl;
    // log prototype: double log(double x);
    cout << "log10(100) = " << log10(100) << endl;
}

// errpors
void f()
{
    errno = 0; // clear old error state
    sqrt(-1);
    if (errno == EDOM)
        cerr << "sqrt() not defined for negative argument" << endl;
    pow(numeric_limits<double>::max(), 2);
    if (errno == ERANGE)
        cerr << "result of pow() too large to represent as a double" << endl;
}

int main(void)
{
    f();
    g();
    return 0;
}