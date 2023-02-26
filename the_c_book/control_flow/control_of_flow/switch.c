// gcc -o switch switch.c && ./switch

#include <stdio.h>
#include <stdlib.h>

main()
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        switch (i)
        {
        case 1:
        case 2:
            printf("%d, 1 or 2\n", i);
        case 7:
            printf("%d, 7\n", i);
        default:
            printf("%d, default\n", i);
        }
    }
    exit(EXIT_SUCCESS);
}
