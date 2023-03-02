// gcc array_of_ten.c -o array_of_ten && ./array_of_ten

#include <stdio.h>

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(void)
{
    printf("9th: %d\n", arr[9]);
    printf("10th: %d\n", arr[10]);
    printf("11th: %d\n", arr[11]);

    return 0;
}