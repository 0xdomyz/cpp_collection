// gcc -o excessive_recursion excessive_recursion.c && ./excessive_recursion

#include <stdio.h>
#include <stdlib.h>

void r_func(void);

void x_func(int depth)
{
    if (depth % 10 == 0)
    {
        printf("depth = %d\n", depth);
    }
    r_func();
}

void r_func(void)
{
    static int depth;
    depth++;
    if (depth > 200)
    {
        printf("excessive recursion\n");
        exit(1);
    }
    else
    {
        /* do usual thing,
         * not shown here.
         * This last action
         * occasionally results in another
         * call on r_func()
         */
        x_func(depth);
    }
    depth--;
}

int main(void)
{
    r_func();
    return (0);
}