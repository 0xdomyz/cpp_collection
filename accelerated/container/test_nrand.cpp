// g++ test_nrand.cpp nrand.cpp -o test_nrand && ./test_nrand 100 100
// g++ test_nrand.cpp nrand.cpp -o test_nrand && ./test_nrand 100000 100

#include "nrand.h"
#include <iostream>
#include <vector>

using namespace std;

// output a vector of random numbers
vector<int> random_vector(int size, int times)
{
    vector<int> v;
    for (int i = 0; i < times; ++i)
    {
        v.push_back(nrand(size));
    }
    return v;
}

// input random size, and number of times to run
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: "
             << " size times" << endl;
        return 1;
    }

    int size = atoi(argv[1]);
    int times = atoi(argv[2]);

    const vector<int> &v = random_vector(size, times);

    // calc 5 stats: min, max, mean
    int min = v[0];
    int max = v[0];
    int sum = 0;

    for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        if (*iter < min)
            min = *iter;
        if (*iter > max)
            max = *iter;
        sum += *iter;
    };

    int mean = sum / v.size();

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "mean: " << mean << endl;

    return 0;
}
