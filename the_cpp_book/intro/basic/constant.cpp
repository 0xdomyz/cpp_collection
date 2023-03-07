// g++ -std=c++11 -o constant constant.cpp && ./constant

#include <iostream>
#include <vector>

using namespace std;

constexpr double square(double x) // square a double precision floating-point number
{
    return x * x;
}

double sum(const vector<double> &v) // sum the elements of a vector<double>
{
    double sum = 0;
    for (auto x : v)
        sum += x;
    return sum;
}

int main()
{

    const int dmv = 17;                        // dmv is a named constant
    int var = 17;                              // var is not a constant
    constexpr double max1 = 1.4 * square(dmv); // OK if square(17) is a constant expression
    // constexpr double max2 = 1.4 * square(var); // error : var is not a constant expression
    const double max3 = 1.4 * square(var); // OK, may be evaluated at run time
    double sum(const vector<double> &);    // sum will not modify its argument (§2.2.5)
    vector<double> v{1.2, 3.4, 4.5};       // v is not a constant
    const double s1 = sum(v);              // OK: evaluated at run time
    // constexpr double s2 = sum(v);          // error : sum(v) not constant expression
    return 0;
}
