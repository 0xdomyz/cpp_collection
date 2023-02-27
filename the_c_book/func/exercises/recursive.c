// compile and run: gcc -o recursive recursive.c && ./recursive

#include <stdio.h>

void print_a_count_down_int_from_100()
{
    static int n = 100;

    if (n == 0)
    {
        return;
    }

    printf("%d \n", n);

    if (n <= 100)
    {
        n--;
        print_a_count_down_int_from_100();
    }
}

int main(void)
{
    print_a_count_down_int_from_100();
}