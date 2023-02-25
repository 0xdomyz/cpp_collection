// gcc -o int_max int_max.c && ./int_max

#include <limits.h>
#include <stdio.h>

int main(void)
{
    printf("The maximum value of an int is %d\n", INT_MAX);
    printf("The minimum value of an int is %d\n", INT_MIN);
    int x = INT_MAX;
    printf("x+1 = %d\n", x + 1);
    return 0;
}