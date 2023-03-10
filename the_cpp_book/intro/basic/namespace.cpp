// g++ -std=c++17 -o namespace namespace.cpp && ./namespace

#include <iostream>
#include <cmath>

namespace My_code
{
    class complex
    {
    public:
        complex(double r, double i) : re{r}, im{i} {}
        double real() const { return re; }
        double imag() const { return im; }

    private:
        double re, im;
    };
    complex sqrt(complex);
    int main();
};

My_code::complex My_code::sqrt(My_code::complex z)
{
    return My_code::complex{std::sqrt(z.real()), std::sqrt(z.imag())};
};

int My_code::main()
{
    complex z{1, 2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    return 0;
};

int main()
{
    return My_code::main();
}