// gcc -o switch_break switch_break.c && ./switch_break

#include <stdio.h>
#include <stdlib.h>
main()
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        printf("i = %d: ", i);
        switch (i)
        {
        case 1:
        case 2:
            printf("1 or 2\n");
            break;
        case 7:
            printf("7\n");
            break;
        default:
            printf("default\n");
        }
    }
    exit(EXIT_SUCCESS);
}