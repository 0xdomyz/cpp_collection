// gcc -o enum enum.c && ./enum

#include <stdio.h>

enum e_tag
{
    a,
    b,
    c,
    d = 20,
    e,
    f,
    g = 20,
    h
} var;

int main(void)
{
    var = a;
    printf("var = %d\n", var);
    var = b;
    printf("var = %d\n", var);
    var = c;
    printf("var = %d\n", var);
    var = d;
    printf("var = %d\n", var);
    var = e;
    printf("var = %d\n", var);
    var = f;
    printf("var = %d\n", var);
    var = g;
    printf("var = %d\n", var);
    var = h;
    printf("var = %d\n", var);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);
    printf("f = %d\n", f);
    printf("g = %d\n", g);
    printf("h = %d\n", h);

    return 0;
}