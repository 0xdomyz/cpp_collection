// compile and run: gcc sin_cos.c -o sin_cos && ./sin_cos

#include <stdio.h>

double power(double x, int y)
{
    double power = 1;
    for (int i = 0; i < y; i++)
    {
        power *= x;
    }
    return power;
}

double factorial(int x)
{
    double factorial = 1;
    for (int i = 1; i <= x; i++)
    {
        factorial *= i;
    }
    return factorial;
}

double abs_val(double x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

double cos(double x)
{
    double cos = 0;
    int i = 0;
    double term;
    double tolerance = 0.000001;

    while (1)
    {
        term = power(-1, i) * power(x, 2 * i) / factorial(2 * i);
        cos += term;
        if (abs_val(term) < tolerance)
        {
            break;
        };
        i++;
    }
    return cos;
}

double sin(double x)
{
    double sin = 0;
    int i = 0;
    double term;
    double tolerance = 0.000001;

    while (1)
    {
        term = power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
        sin += term;
        if (abs_val(term) < tolerance)
        {
            break;
        };
        i++;
    }
    return sin;
}

int main()
{
    double mult = 0.1;
    for (int i = 0; i < 10; i++)
    {
        printf("x = %f, sin(x) = %f, cos(x) = %f\n", mult * i, sin(mult * i), cos(mult * i));
    }

    return 0;
}

// check

// from python
// x = 0.0, sin(x) = 0.0, cos(x) = 1.0)
// x = 0.1, sin(x) = 0.09983341664682815, cos(x) = 0.9950041652780258)
// x = 0.2, sin(x) = 0.19866933079506122, cos(x) = 0.9800665778412416)
// x = 0.3, sin(x) = 0.29552020666133955, cos(x) = 0.955336489125606)
// x = 0.4, sin(x) = 0.3894183423086505, cos(x) = 0.9210609940028851)
// x = 0.5, sin(x) = 0.479425538604203, cos(x) = 0.8775825618903728)
// x = 0.6, sin(x) = 0.5646424733950354, cos(x) = 0.8253356149096783)
// x = 0.7, sin(x) = 0.644217687237691, cos(x) = 0.7648421872844885)
// x = 0.8, sin(x) = 0.7173560908995228, cos(x) = 0.6967067093471654)
// x = 0.9, sin(x) = 0.7833269096274834, cos(x) = 0.6216099682706644)

// from C
// x = 0.000000, sin(x) = 0.000000, cos(x) = 1.000000
// x = 0.100000, sin(x) = 0.099833, cos(x) = 0.995004
// x = 0.200000, sin(x) = 0.198669, cos(x) = 0.980067
// x = 0.300000, sin(x) = 0.295520, cos(x) = 0.955336
// x = 0.400000, sin(x) = 0.389418, cos(x) = 0.921061
// x = 0.500000, sin(x) = 0.479426, cos(x) = 0.877583
// x = 0.600000, sin(x) = 0.564642, cos(x) = 0.825336
// x = 0.700000, sin(x) = 0.644218, cos(x) = 0.764842
// x = 0.800000, sin(x) = 0.717356, cos(x) = 0.696707
// x = 0.900000, sin(x) = 0.783327, cos(x) = 0.621610