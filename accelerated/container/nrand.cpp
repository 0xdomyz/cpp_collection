#include <cstdlib>
#include <stdexcept>
#include "nrand.h"

using namespace std;

const int CUSTOM_RAND_MAX = 32767;

int nrand_large_path(int n);

int nrand(int n)
// return a random integer in the range [0, n)
{
    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");

    if (n > CUSTOM_RAND_MAX)
        return nrand_large_path(n);

    // randome number between 0 and n-1, with equal probability
    const int bucket_size = CUSTOM_RAND_MAX / n;
    int r;

    do
    {
        r = rand() / bucket_size;
    } while (r >= n);

    return r;
}

int custom_rand()
// return a random integer in the range [0, CUSTOM_RAND_MAX)
{
    return nrand(CUSTOM_RAND_MAX);
}

int nrand_large_path(int n)
{
    // n > CUSTOM_RAND_MAX
    const int bucket_number = n / CUSTOM_RAND_MAX;
    const int remainder = n % CUSTOM_RAND_MAX;

    int r;
    int bucket_choice;

    while (true)
    {
        // pick a random bucket, or the remainder
        if (bucket_number + 1 > CUSTOM_RAND_MAX)
        {
            bucket_choice = nrand_large_path(bucket_number + 1);
        }
        else
        {
            bucket_choice = nrand(bucket_number + 1);
        }

        // if picked bucket, then return a random number in that bucket
        if (bucket_choice < bucket_number)
        {
            r = custom_rand();
            return r + bucket_choice * CUSTOM_RAND_MAX;
        }

        // if picked remainder, then return a random number in hypothetical bucket
        if (bucket_choice == bucket_number)
        {
            r = custom_rand();
            // if hypothetical random number is less than remainder, then return hypothetical random number
            if (r < remainder)
            {
                return r + bucket_choice * CUSTOM_RAND_MAX;
            }
            // if hypothetical random number is greater than remainder, then redo from beginning
            else if (r >= remainder)
            {
                continue;
            }
        }
    }

    throw domain_error("program error in nrand_large_path");
}