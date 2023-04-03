// complie and run: g++ -o intro intro.cpp && ./intro

#include <iostream>

using namespace std;

class complex
{ // very simplified complex
    double re, im;

public:
    complex(double r, double i) : re{r}, im{i} {};
    complex operator+(complex);
    complex &operator+=(complex);
    complex operator*(complex);
    double real() const { return re; };
    void real(double d) { re = d; };
    // printable
    friend std::ostream &operator<<(std::ostream &os, const complex &z)
    {
        return os << '(' << z.re << ',' << z.im << ')';
    };
};

complex complex::operator+(complex z)
{
    return complex{re + z.re, im + z.im};
};
complex &complex::operator+=(complex z)
{
    re += z.re;
    im += z.im;
    return *this;
};
complex complex::operator*(complex z)
{
    return complex{re * z.re - im * z.im, re * z.im + im * z.re};
};

void f()
{
    complex a = complex{1, 3.1};
    complex b{1.2, 2};
    complex c{b};

    cout << a << ' ' << b << ' ' << c << '\n';

    a = b + c;
    b = b + c * a;
    c = a * b + complex(1, 2);

    cout << a << ' ' << b << ' ' << c << '\n';
}

void g(complex a, complex b)
{
    a = {1, 2};  // OK: right hand side of assignment
    a += {1, 2}; // OK: right hand side of assignment
    // b = a + {1, 2};        // syntax error
    b = a + complex{1, 2}; // OK
    g(a, {1, 2});          // OK: a function argument is considered an initializer
    // {a, b} = {b, a};       // syntax error
}

int main()
{
    f();
}
