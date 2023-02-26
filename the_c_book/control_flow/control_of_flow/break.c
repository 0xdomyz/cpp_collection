// gcc break.c -o break && ./break

#include <stdio.h>
#include <stdlib.h>
main()
{
    int i;

    for (i = 0; i < 10000; i++)
    {
        if (getchar() == 's')
            break;
        printf("%d\n", i);
    }
    exit(EXIT_SUCCESS);
}