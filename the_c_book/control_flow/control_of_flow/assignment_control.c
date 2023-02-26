// gcc assignment_control.c -o assignment_control && ./assignment_control

#include <stdio.h>
#include <stdlib.h>

main()
{
    int input_c;

    printf("EOF is %d\n", EOF);

    /* The Classic Bit */
    while ((input_c = getchar()) != EOF)
    {
        printf("%c was read\n", input_c);
    }
    exit(EXIT_SUCCESS);
}