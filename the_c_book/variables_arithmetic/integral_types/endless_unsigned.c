// gcc -o endless_unsigned endless_unsigned.c && ./endless_unsigned

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
main()
{
    unsigned int x;
    x = 0;
    while (x >= 0)
    {
        if (x == 0 | x >= UINT_MAX)
        {
            printf("%u\n", x);
        }
        x = x + 1;
    }

    exit(EXIT_SUCCESS);
}