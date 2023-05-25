// g++ median.cpp -o median && ./median

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

template <class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(v.begin(), v.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main()
{

    auto timer = chrono::high_resolution_clock::now();

    vector<int> v = {1, 2, 3, 4, 5};
    int m = median(v);
    printf("median: %d\n", m);

    auto timer2 = chrono::high_resolution_clock::now();
    cout << "Time in nano seconds: " << chrono::duration_cast<chrono::nanoseconds>(timer2 - timer).count() << " ns" << endl;

    vector<double> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    double m2 = median(v2);
    printf("median: %f\n", m2);

    auto timer3 = chrono::high_resolution_clock::now();
    cout << "Time in nano seconds: " << chrono::duration_cast<chrono::nanoseconds>(timer3 - timer2).count() << " ns" << endl;

    // big vector
    vector<int> v3;
    for (int i = 0; i < 1000000; i++)
    {
        v3.push_back(i);
    }
    int m3 = median(v3);
    printf("median: %d\n", m3);

    auto timer4 = chrono::high_resolution_clock::now();
    cout << "Time in nano seconds: " << chrono::duration_cast<chrono::nanoseconds>(timer4 - timer3).count() << " ns" << endl;

    return 0;
}
