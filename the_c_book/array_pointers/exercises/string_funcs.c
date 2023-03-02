// gcc string_funcs.c -o string_funcs && ./string_funcs

#include <stdio.h>
#include <string.h>

int str_compare(const char *s, const char *t);
char *find_char(char c, const char *s);
char *find_str(const char *t, const char *s);

int main(void)
{
    char *s = "Hello, world!";
    char *s2 = "Hello, world!";
    char *t = "world";
    char *t2 = "worldz";

    printf("str_compare(\"%s\", \"%s\") = %d\n", s, t, str_compare(s, t));
    printf("H as int: %d\n", 'H');
    printf("w as int: %d\n", 'w');
    printf("str_compare(\"%s\", \"%s\") = %d\n", s, s2, str_compare(s, s2));

    printf("find_char('%c', \"%s\") = %s\n", 'o', s, find_char('o', s));
    printf("find_char('%c', \"%s\") = %s\n", 'z', s, find_char('z', s));

    printf("find_str(\"%s\", \"%s\") = %s\n", t, s, find_str(t, s));
    printf("find_str(\"%s\", \"%s\") = %s\n", t2, s, find_str(t2, s));

    return 0;
}

int str_compare(const char *s, const char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == 0)
            return 0;
    return *s - *t;
}

char *find_char(char c, const char *s)
{
    for (; *s != c; s++)
        if (*s == 0)
            return NULL;
    return (char *)s;
}

char *find_str(const char *t, const char *s)
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return (char *)s + i;
    }
    // NULL is defined in stdio.h
    // NULL is a macro that expands to ((void *)0)
    return NULL;
}