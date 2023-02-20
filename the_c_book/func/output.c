#include <stdio.h>

// only available in this file
static int line;
static int col;

void output(char c)
{

    // remember current line
    if (c == '\n')
    {
        line++;
        col = 0;
    }
    else if (c == '\t')
    {
        col += 4;
    }
    else
    {
        col++;
    }
    // send to program output
    putchar(c);
}

int current_line(void)
{
    return line;
}

int current_col(void)
{
    return col;
}

void reset_output(void)
{
    line = 0;
    col = 0;
}
