// Compile and run: g++ type_predicates.cpp -o type_predicates && ./type_predicates

#include <type_traits>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
constexpr bool Is_arithmetic()
{
    return std::is_arithmetic<T>::value;
}

bool b1 = Is_arithmetic<int>();    // yes, int is an arithmetic type
bool b2 = Is_arithmetic<string>(); // no, std::str ing is not an arithmetic type

template <typename Scalar>
class complex
{
    Scalar re, im;

public:
    static_assert(
        Is_arithmetic<Scalar>(),
        "Sorr y, I only suppor t complex of arithmetic types");
};

int main(void)
{
    complex<double> z1;

    // complex<string> z2; // error: static assertion failed: Sorry, I only support complex of arithmetic types

    Is_arithmetic<int>(); // yes, int is an arithmetic type

    return 0;
}