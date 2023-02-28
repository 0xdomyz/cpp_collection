// gcc -o call_by_value call_by_value.c && ./call_by_value

#include <stdio.h>
#include <stdlib.h>

void called_func(int, float);

main()
{
    called_func(1, 2 * 3.5);
    exit(EXIT_SUCCESS);
}

void called_func(int iarg, float farg)
{
    float tmp;

    tmp = iarg * farg;
}