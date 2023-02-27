// gcc -o basic basic.c && ./basic

#include <stdio.h>
#include <stdlib.h>

main()
{
    // declare a function
    double return_v, aax1(void);
    return_v = aax1();
    exit(EXIT_SUCCESS);
}

// define a function
double
aax1(void)
{
    /* code for function body */
    return (1.0);
}