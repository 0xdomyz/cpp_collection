// gcc str_eq.c -o str_eq && ./str_eq

#include <stdio.h>

/*
 * Compare two strings for equality.
 * Return 'false' if they are.
 */
int str_eq(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        /*
         * At end of string return 0.
         */
        if (*s1 == 0)
            return (0);
        s1++;
        s2++;
    }
    /* Difference detected! */
    return (1);
}

int main()
{
    char *s1 = "Hello";
    char *s2 = "Hello";
    char *s3 = "Hello World";
    char *s4 = "Hello World";

    str_eq(s1, s2) == 0 ? printf("s1 == s2\n") : printf("s1 != s2\n");
    str_eq(s3, s4) == 0 ? printf("s3 == s4\n") : printf("s3 != s4\n");

    return (0);
}