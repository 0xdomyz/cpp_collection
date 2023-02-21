// gcc -o prime prime.c && ./prime

/*
 *
 * Dumb program that generates prime numbers.
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
    int this_number, divisor, not_prime, total_primes;

    this_number = 3;
    total_primes = 0;

    while (this_number < 10000)
    {
        divisor = this_number / 2;
        not_prime = 0;
        while (divisor > 1)
        {
            if (this_number % divisor == 0)
            {
                not_prime = 1;
                divisor = 0; // exit the loop
            }
            else
                divisor = divisor - 1;
        }

        if (not_prime == 0)
        {
            printf("%d is a prime number\n", this_number);
            total_primes = total_primes + 1;
        }
        this_number = this_number + 1;
    }

    printf("Total primes found: %d\n", total_primes);
    exit(EXIT_SUCCESS);
}