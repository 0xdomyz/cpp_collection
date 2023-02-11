// gcc -o array_of_string array_of_string.c && ./array_of_string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to print array of strings
void print_array_of_strings(char **s, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%s", s[i]);
        printf("{%lu}", strlen(s[i]));
        printf("\n");
    }
}

int main(void)
{

    // array of characters
    char c[] = {'h', 'e', 'l', 'l', 'o'};

    // array of integers
    int a[] = {1, 2, 3, 4, 5};

    // array of int
    int i[] = {1, 2, 3, 4, 5};
    // int pointer
    int *p = i;

    // array of strings
    char *s[] = {"aaa AA", "bbb BBBB", "ccc C", "dddd DDD", "e EEE"};
    int n = sizeof(s) / sizeof(s[0]);

    // pointer to array of strings
    char **t = s;
    printf("size of pointer to array of strings %lu \n", sizeof(t));
    printf("size of array of strings %lu \n", sizeof(s));
    printf("size of array of strings dereference %lu \n", sizeof(*s));
    printf("number of elements in array of strings %lu \n", sizeof(s) / sizeof(s[0]));

    // function usages
    print_array_of_strings(s, n);

    // reverse a string
    // char *str = "hello";
    // int len = strlen(str);
    // char *rev = malloc(len + 1);
    // for (int i = 0; i < len; i++)
    // {
    //     rev[i] = str[len - i - 1];
    // }
    // rev[len] = '\0';
    // printf("%s\n", rev);

    // array of pointers to integers
    // int *p[] = {&a[0], &a[1], &a[2], &a[3], &a[4]};

    // array of pointers to strings
    // char *t[] = {s[0], s[1]};

    // array of pointers to pointers to integers
    // int **q[] = {p[0], p[1], p[2], p[3], p[4]};

    return 0;
}
