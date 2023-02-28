// gcc pointer_to_func.c -o pointer_to_func && ./pointer_to_func

#include <stdio.h>
#include <stdlib.h>

void func(int);

main()
{
    void (*fp)(int);

    fp = func;

    (*fp)(1);
    fp(2);

    exit(EXIT_SUCCESS);
}

void func(int arg)
{
    printf("%d\n", arg);
}