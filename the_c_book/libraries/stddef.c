// gcc -o stddef stddef.c && ./stddef

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

main()
{
    // NULL is a macro that expands to an integer constant expression with the value 0.
    // FILE *fp;
    //
    // if((fp = fopen("somefile", "r")) != NULL){
    //         /* and so on */

    // offsetof() is a macro that expands to an integer constant expression that has
    // the value of the offset in bytes of the member
    size_t distance;
    struct x
    {
        int a, b, c;
    } s_tr;

    // distance = offsetof(s_tr, c);
    distance = offsetof(struct x, c);

    printf("Offset of x.c is %lu bytes\n",
           (unsigned long)distance);

    exit(EXIT_SUCCESS);
}