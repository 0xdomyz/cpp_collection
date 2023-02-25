// gcc -o bits_on_off bits_on_off.c && ./bits_on_off

#include <stdio.h>

int main()
{
    int x, y;

    x = 123456789;
    printf("x = %x\n", x);
    printf("turn off all but the low-order four bits in x: %x\n", x & 0xf);

    x = 123456789;
    printf("x = %x\n", x);
    printf("turn on all but the low-order four bits in x: %x\n", x | ~0xf);

    x = 123456789;
    printf("x = %x\n", x);
    printf("turn off only the low-order four bits in x: %x\n", x & ~0xf);

    x = 123456789;
    printf("x = %x\n", x);
    printf("obtain the low-order four bits of x: %x\n", x & 0xf);
    printf("obtain the low-order eight bits of x: %x\n", x & 0xff);

    y = 12345678;
    printf("y = %x\n", y);
    x = 54136464;
    printf("x = %x\n", x);
    printf("put the low-order four bits of y into the high-order four bits of x: %x\n", (x & ~0xf0) | ((y & 0xf) << 4));
}