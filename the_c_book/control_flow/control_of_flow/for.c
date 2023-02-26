// gcc -o for for.c && ./for

#include <stdio.h>
#include <stdlib.h>
main()
{
    int i;

    i = 0;
    while (i <= 10)
    {
        printf("%d\n", i);
        i++;
    }

    /* the same done using ``for'' */
    for (i = 0; i <= 10; i++)
    {
        printf("%d\n", i);
    }

    // infinite loop
    for (;;)
        break;
    while (1)
        break;
    exit(EXIT_SUCCESS);
}