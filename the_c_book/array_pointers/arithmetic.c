// gcc -o arithmetic arithmetic.c && ./arithmetic

#include <stdio.h>

int main(void)
{
    int x[100];
    int *pi, *cpi = &x[99]; /* cpi points to the last element of x */

    pi = x;
    if ((cpi - pi) != 99)
        printf("Error\n");

    pi = cpi;
    pi++; /* increment past end of x */
    if ((pi - cpi) != 1)
        printf("Error\n");
}