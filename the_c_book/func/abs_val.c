// compile and run: gcc abs_val.c -o abs_val && ./abs_val

#include <stdio.h>

int abs_val(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}

void print_abs_val(int n)
{
    printf("The absolute value of %d is %d\n", n, abs_val(n));
}

void main(void)
{

    print_abs_val(5);
    print_abs_val(-5);
    print_abs_val(0);
    print_abs_val(-0);
    print_abs_val(1.2);
}