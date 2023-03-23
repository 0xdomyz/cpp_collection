// g++ limits.cpp -o limits -std=c++11 && ./limits

#include <limits>
#include <climits>
#include <iostream>

using namespace std;

void f(double d, int i)
{
    char classification[numeric_limits<unsigned char>::max()];
    if (numeric_limits<unsigned char>::digits == numeric_limits<char>::digits)
    {
        // chars are unsigned
    }
    if (i < numeric_limits<short>::min() || numeric_limits<short>::max() < i)
    {
        // i cannot be stored in a short without loss of digits
    }
    if (0 < d && d < numeric_limits<double>::epsilon())
        d = 0;

    // type Quad
    typedef long double Quad;
    // typedef means that Quad is an alias for long double
    if (numeric_limits<Quad>::is_specialized)
    {
        // limits infor mation is available for type Quad
    }
}

// example of c limit macros
void g(void)
{
    cout << "CHAR_BIT = " << CHAR_BIT << endl;
    cout << "CHAR_MAX = " << CHAR_MAX << endl;
    cout << "CHAR_MIN = " << CHAR_MIN << endl;
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "INT_MIN = " << INT_MIN << endl;
    cout << "LONG_MAX = " << LONG_MAX << endl;
    cout << "LONG_MIN = " << LONG_MIN << endl;
    cout << "SCHAR_MAX = " << SCHAR_MAX << endl;
    cout << "SCHAR_MIN = " << SCHAR_MIN << endl;
    cout << "SHRT_MAX = " << SHRT_MAX << endl;
    cout << "SHRT_MIN = " << SHRT_MIN << endl;
    cout << "UCHAR_MAX = " << UCHAR_MAX << endl;
    cout << "UINT_MAX = " << UINT_MAX << endl;
    cout << "ULONG_MAX = " << ULONG_MAX << endl;
    cout << "USHRT_MAX = " << USHRT_MAX << endl;
}

int main(void)
{
    g();
    return 0;
}