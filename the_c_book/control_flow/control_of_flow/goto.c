// gcc goto.c -o goto && ./goto

#include <stdio.h>
#include <stdlib.h>
main()
{
    int i;

    for (i = -10; i < 10; i++)
    {
        if (i == 0)
            goto L1;
        printf("%f\n", 15.0 / i);
        /*
         * Lots of other statements .....
         */
    }
L1:
    exit(EXIT_SUCCESS);
}
