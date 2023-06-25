// g++ test_median.cpp -o test_median && ./test_median

#include <iostream>
#include <vector>
#include "median.h"

using namespace std;

int main()
{
    // test vector of int
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(rand() % 100);
    }

    int m1 = median<int>(v1.begin(), v1.end());

    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "median: " << m1 << endl;

    // test built in array of double
    double v2[] = {9.9, 2.2, 3.3, 4.4, 5.5};

    float m2 = median<float>(v2, v2 + 5);

    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "median: " << m2 << endl;
}