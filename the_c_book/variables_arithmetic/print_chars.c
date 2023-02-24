// gcc print_chars.c -o print_chars && ./print_chars

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
    char c;

    c = CHAR_MIN;
    while (c != CHAR_MAX)
    {
        printf("%d\n", c);
        c = c + 1;
    }

    exit(EXIT_SUCCESS);
}