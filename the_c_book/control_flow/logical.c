// gcc -o logical logical.c && ./logical

#include <stdio.h>

int main(void)
{

    // and operator
    printf("1 && 1 = %d\n", 1 && 1);
    printf("1 && 0 = %d\n", 1 && 0);
    printf("0 && 1 = %d\n", 0 && 1);
    printf("0 && 0 = %d\n", 0 && 0);

    // or operator
    printf("1 || 1 = %d\n", 1 || 1);
    printf("1 || 0 = %d\n", 1 || 0);
    printf("0 || 1 = %d\n", 0 || 1);
    printf("0 || 0 = %d\n", 0 || 0);

    // not operator
    printf("!1 = %d\n", !1);
    printf("!0 = %d\n", !0);

    // not divide by zero
    int a = 0;
    int b = 10;
    if (a != 0 && b / a > 5)
    {
        printf("b/a > 5\n");
    }
    /* alternative */
    if (a && b / a > 5)
    {
        printf("b/a > 5\n");
    }

    // not use not
    if (!a)
    {
    }
    /* alternative */
    if (a == 0)
    {
    }

    if (!(a > b))
    {
    }
    /* alternative */
    if (a <= b)
    {
    }

    int c = 0;
    int d = 10;

    if (!(a > b && c < d))
    {
    }
    /* alternative */
    if (a <= b || c >= d)
    {
    }

    return 0;
}