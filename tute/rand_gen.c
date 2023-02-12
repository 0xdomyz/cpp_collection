// compile: gcc rand_gen.c -o rand_gen -lm && ./rand_gen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
    // prompt for an integer
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("You entered: %d\n", n);

    // get current time as an integer
    int t = time(NULL);
    printf("The current time is: %d\n", t);

    // initialize the random number generator with a seed
    srand(t);

    // array of n random numbers, bounded between 2 numbers
    int *numbers = (int *)malloc(n * sizeof(int));
    int min = 1000;
    int max = 9999;
    for (int i = 0; i < n; i++)
    {
        int num = rand() % (max - min + 1) + min;
        numbers[i] = num;
    }

    // mean of the array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }
    float mean = (float)sum / n;

    // standard deviation of the array
    float sum_sq = 0;
    for (int i = 0; i < n; i++)
    {
        sum_sq += (numbers[i] - mean) * (numbers[i] - mean);
    }
    float std_dev = sqrt(sum_sq / n);

    // print the array, with each row containing 10 numbers, sperated by a space
    printf("The array is: ");
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // print the mean and standard deviation
    printf("The mean is: %f\n", mean);
    printf("The standard deviation is: %f\n", std_dev);

    // free the array
    free(numbers);

    // prompt for key press to exit
    printf("Press any key to exit...");
    getchar();
    getchar();

    return 0;
}