// gcc -o use_lib1 use_lib1.c lib1.c && ./use_lib1

#include <stdio.h>

int callable(void);

int main(void)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", callable());
    }
    return (0);
}