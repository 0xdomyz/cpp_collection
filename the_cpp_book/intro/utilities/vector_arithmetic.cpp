// Compile and run: g++ vector_arithmetic.cpp -o vector_arithmetic && ./vector_arithmetic

#include <iostream>
#include <valarray>

using namespace std;

// template<typename T>
// class valarray {
// // ...
// };

double f(valarray<double> &a1, valarray<double> &a2)
{
    valarray<double> a = a1 * 3.14 + a2 / a1; // numer ic array operators *, +, /, and =
    a2 += a1 * 3.14;
    a = abs(a);
    double d = a2[7];
    return d;
}

int main(void)
{
    valarray<double> a1(10);
    valarray<double> a2(10);
    for (int i = 0; i < 10; ++i)
    {
        a1[i] = i;
        a2[i] = i * i;
    }
    double d = f(a1, a2);
    cout << d << '\n';
}