// gcc maybe_chars.c -o maybe_chars && ./maybe_chars

#include <stdio.h>
#include <stdlib.h>
main()
{
    char c;

    c = 'a';
    while (c <= 'z')
    {
        printf("value %d char %c\n", c, c);
        c = c + 1;
    }

    printf("A is %d\n", 'A');
    printf("B is %d\n", 'B');
    printf("C is %d\n", 'C');
    printf("D is %d\n", 'D');
    printf("E is %d\n", 'E');
    printf("F is %d\n", 'F');
    printf("G is %d\n", 'G');
    printf("H is %d\n", 'H');
    printf("I is %d\n", 'I');
    printf("J is %d\n", 'J');
    printf("K is %d\n", 'K');
    printf("L is %d\n", 'L');
    printf("M is %d\n", 'M');
    printf("N is %d\n", 'N');
    printf("O is %d\n", 'O');
    printf("P is %d\n", 'P');
    printf("Q is %d\n", 'Q');
    printf("R is %d\n", 'R');
    printf("S is %d\n", 'S');
    printf("T is %d\n", 'T');
    printf("U is %d\n", 'U');
    printf("V is %d\n", 'V');
    printf("W is %d\n", 'W');
    printf("X is %d\n", 'X');
    printf("Y is %d\n", 'Y');
    printf("Z is %d\n", 'Z');

    exit(EXIT_SUCCESS);
}
