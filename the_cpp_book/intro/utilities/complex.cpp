// Compile and run: g++ complex.cpp -o complex && ./complex

#include <cmath>
#include <iostream>
#include <complex>

using namespace std;

// template <typename Scalar>
// class complex
// {
// public:
//     complex(const Scalar &re = {}, const Scalar &im = {});
//     // ...
// };

complex<double> f(complex<double> fl, complex<double> db)
{
    complex<long double> ld{fl + sqrt(db)};
    db += fl * 3.0;
    fl = pow(1.0 / fl, 2);
    return fl;
}

int main(void)
{
    complex<double> fl{1.0, 2.0};
    complex<double> db{3.0, 4.0};
    complex<double> res = f(fl, db);
    cout << res << '\n';
}