// gcc -o prime_pairs prime_pairs.c && ./prime_pairs

/*
 *
 * Dumb program that generates prime numbers.
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
    int this_number, last_prime, divisor, not_prime, total_primes, total_prime_pairs;

    this_number = 3;
    last_prime = 2;
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
            if (this_number - last_prime == 2)
            {
                printf("%d, %d are a prime pair\n", last_prime, this_number);
                total_prime_pairs = total_prime_pairs + 1;
            }
            last_prime = this_number;
            total_primes = total_primes + 1;
        }
        this_number = this_number + 1;
    }

    printf("Total primes found: %d\n", total_primes);
    printf("Total prime pairs found: %d\n", total_prime_pairs);
    exit(EXIT_SUCCESS);
}