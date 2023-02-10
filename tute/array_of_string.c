// gcc -o array_of_string array_of_string.c && ./array_of_string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // array of strings
    char *s[] = {"hello", "world"};

    // array of characters
    char c[] = {'h', 'e', 'l', 'l', 'o'};

    // size of array of strings
    printf("size of s: %lu \n", sizeof(s));

    // number of elements in array of strings
    printf("number of elements in s: %lu \n", sizeof(s) / sizeof(s[0]));

    int n = sizeof(s) / sizeof(s[0]);

    // loop over array of strings and print each string
    for (int i = 0; i < n; i++)
    {
        printf("%s", s[i]);
        printf("{%lu}", sizeof(s[i]));
        printf("\n");
    }

    // reverse loop over array of strings and print each string
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%s", s[i]);
        printf("{%lu}", sizeof(s[i]));
        printf("\n");
    }

    // reverse a string
    char *str = "hello";
    int len = strlen(str);
    char *rev = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    printf("%s\n", rev);

    // array of integers
    int a[] = {1, 2, 3, 4, 5};

    // // array of pointers to integers
    // int *p[] = {&a[0], &a[1], &a[2], &a[3], &a[4]};

    // // array of pointers to strings
    // char *t[] = {s[0], s[1]};

    // // array of pointers to pointers to integers
    // int **q[] = {p[0], p[1], p[2], p[3], p[4]};

    return 0;
}
