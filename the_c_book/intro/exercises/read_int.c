// gcc -o read_int read_int.c && ./read_int

#include <stdio.h>

int read_int(void)
{
    int n = 0;
    int ch;
    while ((ch = getchar()) != '\n')
    {
        n = n * 10 + (ch - '0');
        // convert char to int, assuming ASCII, which is true for '0'-'9'
    }
    return n;
}

int main(void)
{
    // int n;
    // printf("Enter a number: ");
    // n = read_int();
    // printf("You entered %d\n", n);
    // return 0;

    int numbers[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a number: ");
        int n = read_int();
        printf("You entered %d\n", n);
        numbers[i] = n;
    }

    // sort the array
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // print the array
    printf("Sorted array: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
