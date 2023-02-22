// gcc -o max_real max_real.c && ./max_real

#include <stdio.h>

long int power(int base, int exponent)
{
    long int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int main(void)
{
    printf("size of float: %ld\n", sizeof(float));
    printf("size of double: %ld\n", sizeof(double));
    printf("size of long double: %ld\n", sizeof(long double));
    // sizeof returns the size of a variable in bytes

    // power
    printf("power: %ld\n", power(2, 3));
    printf("power: %ld\n", power(256, 4));

    // number of therotical numbers that can be represented by a byte is 256
    int each_byte = 256;
    int float_bytes = sizeof(float);
    printf("float bytes: %d\n", (int)float_bytes);
    int float_numbers = power(each_byte, float_bytes);
    printf("float numbers: %d\n", float_numbers);

    printf("max float: %f\n", (float)float_numbers);

    int double_numbers = power(each_byte, sizeof(double));
    printf("max double: %f\n", (double)double_numbers);

    int long_double_numbers = power(each_byte, sizeof(long double));
    printf("max long double: %Lf\n", (long double)long_double_numbers);

    // max float
    float x = 16777216;
    printf("%f\n%f\n", x, x + 1.0f);

    // max double
    double y = 9007199254740992;
    printf("%f\n%f\n", y, y + 1.0);

    // find out max long double
    long double z = 18446744073709550000.000000;
    while (z + 1.0 != z)
    {
        z += 100.0;
    }
    printf("max long double: %Lf\n", z);

    // max long double
    long double a = 18446744073709551668.000000;
    printf("%Lf\n%Lf\n", a, a + 1.0);
}
