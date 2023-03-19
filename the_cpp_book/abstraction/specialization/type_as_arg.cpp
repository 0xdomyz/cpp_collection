// g++ type_as_arg.cpp -o type_as_arg -std=c++11 && ./type_as_arg

#include <iostream>
#include <complex>
#include <vector>

using namespace std;

template <typename T>
void f(T)
{
    cout << "T is " << typeid(T).name() << endl;
};

template <typename T>
class X2
{
    // ...
};

class X
{
    class M
    { /* ... */
    };
    // ...
    void mf();
};

void f2()
{
    struct S
    { /* ... */
    };
    vector<S> vs; // OK
    // vector<X::M> vm; // error : X::M is private
    // ...
};

// void M::mf()
// {
//     // vector<S> vs; // error : no S in scope
//     vector<M> vm; // OK
//     // ...
// };

int main(void)
{
    f(1);                  // T deduced to be int
    f<double>(1);          // T is double
    f<complex<double>>(1); // T is complex<double>

    X2<double> x3;          // T is double
    X2<complex<double>> x4; // T is complex<double>

    vector<double> x5;          // vector of doubles
    vector<complex<double>> x6; // vector of complex<double
}