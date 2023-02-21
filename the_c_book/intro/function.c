// gcc -o function function.c && ./function

#include <stdio.h>
// #include <stdlib.h>

/*
 * Tell the compiler that we intend
 * to use a function called show_message.
 * It has no arguments and returns no value
 * This is the "declaration".
 *
 */

void show_message(void);
/*
 * Another function, but this includes the body of
 * the function. This is a "definition".
 */
main()
{
    int count;

    count = 0;
    while (count < 10)
    {
        show_message();
        count = count + 1;
    }
    // while (expression)
    //     statement

    return (0); // return expression;
    // alternative, need to include stdlib.h:
    // con is that it is not portable, and it is not type safe
    // details: https://stackoverflow.com/questions/107664/what-is-the-difference-between-exit-and-return-in-c
    // exit(0);
    // exit(EXIT_SUCCESS);
}

/*
 * The body of the simple function.
 * This is now a "definition".
 */
void show_message(void)
{
    printf("hello\n");
}

void do_nothing(void) {}
