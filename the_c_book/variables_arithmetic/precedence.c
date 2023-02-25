// gcc -o precedence precedence.c && ./precedence

#include <stdio.h>

char c;
int i;
unsigned u;
float f;

int main(void)
{
    c = 'a';
    i = 1;
    u = 2;
    f = 3.0;

    printf("c = %c, i = %d, u = %u, f = %f\n", c, i, u, f);

    printf("c = u * f + 2.6L, %c\n", u * f + 2.6L);
    printf("u += --f / u \% 3, %u\n", u + --f / u % 3);
    printf("i <<= u * -++f, %d\n", i << u * -++f);
    printf("u = i + 3 + 4 + 3.1, %u\n", i + 3 + 4 + 3.1);
    printf("u = 3.1 + i + 3 + 4, %u\n", 3.1 + i + 3 + 4);
    printf("c = (i << - --f) & 0xf, %c\n", (i << - --f) & 0xf);
}