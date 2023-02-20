// gcc -o walk_thru_array walk_thru_array.c && ./walk_thru_array

#include <stdio.h>

int main()
{
    int ar[20], *ip;

    for (ip = &ar[0]; ip < &ar[20]; ip++)
        *ip = 0;

    for (ip = &ar[0]; ip < &ar[20]; ip++)
        printf("%d \n", *ip);
}