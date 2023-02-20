// compile: gcc -o test_output test_output.c output.c && ./test_output

#include <assert.h>
#include <string.h>
#include <stdio.h>

void output(char c);

int current_line(void);

int current_col(void);

void reset_output(void);

void test_output(char *s, int line, int col)
{
    int i = 0;
    while (s[i] != '\0')
    {
        output(s[i]);
        i++;
    }

    printf("\n");
    printf("current_line() ==  %d\n", current_line());
    printf("current_col() ==  %d\n", current_col());

    assert(current_line() == line);
    assert(current_col() == col);
    printf("\ntest_output passed\n");

    reset_output();
}

int main(void)
{
    test_output("Hello, world!", 0, 13);
    test_output("aaa\nbbb", 1, 3);
    test_output("aaa\nbbb\ncccd", 2, 4);
}