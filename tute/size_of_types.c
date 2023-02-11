// print size of types
// gcc -o size_of_types size_of_types.c && ./size_of_types

#include <stdio.h>

int main(void)
{
    printf("Size of char: %ld bytes\n", sizeof(char));
    printf("Size of short: %ld bytes\n", sizeof(short));
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of long: %ld bytes\n", sizeof(long));
    printf("Size of long long: %ld bytes\n", sizeof(long long));
    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));
    printf("Size of long double: %ld bytes\n", sizeof(long double));
    printf("Size of pointer: %ld bytes\n", sizeof(void *));

    // same in loop, but need type of type
    // char *types[] = {"char", "short", "int", "long", "long long", "float", "double", "long double", "pointer"};

    // type type

    // int i;
    // for (i = 0; i < 9; i++)
    // {
    //     printf("Size of %s: %ld bytes\n", types[i], sizeof(types[i]));
    // }

    return 0;
}
