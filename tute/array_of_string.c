// gcc -o array_of_string array_of_string.c && ./array_of_string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array_of_strings(char **s, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%s", s[i]);
        printf("{%lu}", strlen(s[i]));
        printf("\n");
    }
}

char *reverse_string(char *str)
{
    int len = strlen(str);
    char *rev = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

char **reverse_array_of_strings(char **s, int n)
{
    char **rev = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        rev[i] = reverse_string(s[i]);
    }
    return rev;
}

char *max_length_string(char **s, int n)
{
    int max = strlen(s[0]);
    char *max_str = s[0];
    for (int i = 0; i < n; i++)
    {
        int len = strlen(s[i]);
        if (len > max)
        {
            max = len;
            max_str = s[i];
        }
    }
    return max_str;
}

char *min_length_string(char **s, int n)
{
    int min = strlen(s[0]);
    char *min_str = s[0];
    for (int i = 0; i < n; i++)
    {
        int len = strlen(s[i]);
        if (len < min)
        {
            min = len;
            min_str = s[i];
        }
    }
    return min_str;
}

int compare(const void *num1, const void *num2)
{
    // char **a = (char**)num1;
    // char **b = (char**)num2;
    // return strcmp(*a, *b);
    return strcmp(*(char **)num1, *(char **)num2);
}

int main(void)
{

    // array of strings
    char *s[] = {"aaa Ab", "bbb Bcdsag", "ccc asdf", "dddd dasrgbf", "e bh"};
    int n = sizeof(s) / sizeof(s[0]);

    // array pointer and length as argument to func
    printf("array of strings:\n");
    print_array_of_strings(s, n);
    printf("\n");

    // max length string
    char *max_str = max_length_string(s, n);
    printf("max length string: %s", max_str);
    printf("{%lu}\n", strlen(max_str));

    printf("address of max_str: %p\n", max_str);
    printf("address of s[1]: %p\n", s[1]);
    printf("\n");

    // min length string
    char *min_str = min_length_string(s, n);
    printf("min length string: %s", min_str);
    printf("{%lu}\n", strlen(min_str));
    printf("\n");

    // reverse array of strings
    char **rev_s = reverse_array_of_strings(s, n);
    printf("reverse array of strings:\n");
    print_array_of_strings(rev_s, n);
    printf("\n");

    // qsort
    printf("qsort:\n");
    qsort(rev_s, n, sizeof(char *), compare);
    printf("sorted array of strings:\n");
    print_array_of_strings(rev_s, n);
    printf("\n");

    // free memory
    for (int i = 0; i < n; i++)
    {
        free(rev_s[i]);
    }
    free(rev_s);

    // prompt for program to exit
    printf("Press enter to exit");
    getchar();

    return 0;
}
