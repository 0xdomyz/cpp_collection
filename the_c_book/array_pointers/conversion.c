// gcc -o conversion conversion.c && ./conversion

#include <stdio.h>

int main(void)
{
    int i;
    int *ip;
    void *vp;

    ip = &i;
    vp = ip;
    ip = vp;
    if (ip != &i)
        printf("Compiler error\n");

    const int *cpi;

    ip = &i;
    cpi = ip; /* permitted */
    if (cpi != ip)
        printf("Compiler error\n");
    ip = cpi; /* not permitted */
}