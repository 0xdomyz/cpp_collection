// gcc -o assert assert.c && ./assert

// #define NDEBUG // to disable assert()
#include <assert.h>
#include <stdio.h>

void func(void)
{
    int c;
    assert((c = getchar()) != 'x');
    putchar(c);
    putchar('\n');
}

int main(void)
{
    func();
    return 0;
}