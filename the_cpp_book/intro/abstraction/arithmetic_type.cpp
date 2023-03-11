// g++ -std=c++17 -o arithmetic_type arithmetic_type.cpp && ./arithmetic_type

#include <iostream>
#include <cmath>

class complex
{
    double re, im; // representation: two doubles
public:
    complex(double r, double i) : re{r}, im{i} {} // construct complex from two scalars
    complex(double r) : re{r}, im{0} {}           // construct complex from one scalar
    complex() : re{0}, im{0} {}                   // default complex: {0,0}
    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }
    complex &operator+=(complex z)
    {
        re += z.re, im += z.im;
        return *this;
    } // add to re and im
    // and return the result
    complex &operator-=(complex z)
    {
        re -= z.re, im -= z.im;
        return *this;
    }
    complex &operator*=(complex); // defined out-of-class somewhere
    complex &operator/=(complex); // defined out-of-class somewhere
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; } // unar y minus
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

complex &complex::operator*=(complex z)
{
    double r = re * z.re - im * z.im;
    double i = re * z.im + im * z.re;
    re = r, im = i;
    return *this;
}

complex &complex::operator/=(complex z)
{
    double denom = z.re * z.re + z.im * z.im;
    if (denom == 0)
        throw std::runtime_error("divide by zero");
    double r = (re * z.re + im * z.im) / denom;
    double i = (im * z.re - re * z.im) / denom;
    re = r, im = i;
    return *this;
}

bool operator==(complex a, complex b) // equal
{
    return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) // not equal
{
    return !(a == b);
}
complex sqrt(complex z)
{
    double r = std::sqrt((z.real() + std::sqrt(z.real() * z.real() + z.imag() * z.imag())) / 2);
    double i = std::sqrt((-z.real() + std::sqrt(z.real() * z.real() + z.imag() * z.imag())) / 2);
    return complex(r, i);
}

void f(complex z)
{
    complex a{2.3}; // construct {2.3,0.0} from 2.3
    complex b{1 / a};

    complex c{a + z * complex{1, 2.3}};
    // ...
    if (c != b)
        c = -(b / a) + 2 * b;

    c = a + z * complex{1, 2.3};

    std::cout << c.real() << " " << c.imag() << std::endl;

    complex d = sqrt(c);
    std::cout << d.real() << " " << d.imag() << std::endl;
}

int main()
{
    f({1.2, 3.4});
}
