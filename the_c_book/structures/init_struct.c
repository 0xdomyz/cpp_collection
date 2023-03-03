// gcc -o init_struct init_struct.c && ./init_struct

#include <stdio.h>
#include <stdlib.h>

struct s
{
    int a;
    char b;
    char *cp;
} ex_s = {
    1, 'a', "hello"};

struct s2
{
    int a;
    struct ss
    {
        int c;
        char d;
    } e;
} x[] = {
    {1, {2, 'a'}},
    {3, {4, 'b'}}};

main()
{
    struct s first = ex_s;
    struct s second = {
        2, 'b', "byebye"};

    struct s2 third = {
        5, {6, 'c'}};

    exit(EXIT_SUCCESS);
}