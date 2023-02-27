// gcc -o return return.c && ./return

#include <stdio.h>

int non_space(void)
{
    int c;
    while ((c = getchar()) == '\t' || c == '\n' || c == ' ')
        ; /* empty statement */
    return (c);
}

int main(void)
{
    int c;
    c = non_space();
    printf("c = %d\n", c);
    return (0);
}