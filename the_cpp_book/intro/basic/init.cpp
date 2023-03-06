// g++ -o init init.cpp && ./init

#include <complex>
#include <iostream>
#include <vector>

double d1 = 2.3;
double d2{2.3};
std::complex<double> z = 1; // a complex number with double-precision floating-point scalars
std::complex<double> z2{d1, d2};
std::complex<double> z3 = {1, 2};     // the = is optional with { ... }
std::vector<int> v{1, 2, 3, 4, 5, 6}; // a vector of ints

// conversion
int i1 = 7.2; // i1 becomes 7
// int i2{7.2};    // error : floating-point to integer conversion
// int i3 = {7.2}; // error : floating-point to integer conversion (the = is redundant

// auto
auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123;  // an int
auto d = 1.2;  // a double
double y = 2.5;
auto x = sqrt(y); // z has the type of whatever sqr t(y) retur ns

int main()
{
    std::cout << "d1 == " << d1 << "\n";
    std::cout << "d2 == " << d2 << "\n";
    std::cout << "z == " << z << "\n";
    std::cout << "z2 == " << z2 << "\n";
    std::cout << "z3 == " << z3 << "\n";
    std::cout << "v == " << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << "\n";
    std::cout << "i1 == " << i1 << "\n";

    // size of
    std::cout << "size of i == " << sizeof(i) << "\n";

    std::cout << "size of x == " << sizeof(x) << "\n";
    std::cout << "size of y == " << sizeof(y) << "\n";

    return 0;
}