// gcc -o size_of_limit size_of_limit.c && ./size_of_limit

#include <stdio.h>
#include <stdlib.h>

const char arr[] = "hello";
const char *cp = arr;
main()
{

    printf("Size of arr %lu\n", (unsigned long)sizeof(arr));
    printf("Size of *cp %lu\n", (unsigned long)sizeof(*cp));
    exit(EXIT_SUCCESS);
}