// gcc -o wchar_t wchar_t.c && ./wchar_t

#include <stdio.h>
#include <stddef.h>

int main(void)
{
    wchar_t c = L'x';
    printf("c = %lc, number = %d\n", c, c);

    printf("? = %lc, number = %d\n", L'?', L'?');

    printf("/ = %lc, number = %d\n", L'/', L'/');
    printf("/ = %c, number = %d\n", '/', '/');

    printf("<a> = %lc, number = %d\n", L"<a>"[0], L"<a>"[0]);
    printf("<b> = %lc, number = %d\n", L"<b>"[0], L"<b>"[0]);
    printf("$ = %lc, number = %d\n", L"$"[0], L"$"[0]);

    printf("€ number = %d\n", L'€');

    // extended ASCII
    printf("Š number = %d\n", L'Š');

    // print extended ASCII int value
    printf("Š = %d\n", L'Š');
    // print extended ASCII char value
    printf("Š = %c\n", L'Š');
    // print extended ASCII as wchar_t
    printf("Š = %lc\n", L'Š');

    return 0;
}