#include <cstdlib>
#include <stdexcept>
#include "nrand.h"

using namespace std;

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    // randome number between 0 and n-1, with equal probability
    const int bucket_size = RAND_MAX / n;
    int r;

    do
    {
        r = rand() / bucket_size;
    } while (r >= n);

    return r;
}