// g++ vector_median.cpp -o vector_median && ./vector_median

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

template <class Ran, class T>
T median_in_place(Ran begin, Ran end)
{
    // typedef typename iterator_traits<Ran>::difference_type diff;
    // diff size = distance(begin, end);
    typedef typename vector<T>::size_type diff;
    diff size = end - begin;

    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(begin, end);

    diff mid = size / 2;
    return size % 2 == 0 ? (*(begin + mid) + *(begin + mid - 1)) / 2 : *(begin + mid);
}

chrono::nanoseconds time_from_last_call(void)
{
    static auto last = chrono::high_resolution_clock::now();
    auto now = chrono::high_resolution_clock::now();
    auto res = chrono::duration_cast<chrono::nanoseconds>(now - last);
    last = now;
    return res;
}

void test_big_vectors()
{
    // random bigger one to test in place
    vector<int> v4;
    for (int i = 0; i < 10000000; i++)
    {
        v4.push_back(rand() % 100000 * 0.1);
    }

    time_from_last_call();
    int m5 = median(v4);
    printf("median: %d\n", m5);
    cout << "time: " << time_from_last_call().count() << endl;

    time_from_last_call();
    int m6 = median_in_place<vector<int>::iterator, int>(v4.begin(), v4.end());
    printf("median: %d\n", m6);
    cout << "time: " << time_from_last_call().count() << endl;

    // speed of copying a big vector
    time_from_last_call();
    vector<int> v5 = v4;
    cout << "time: " << time_from_last_call().count() << endl;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5};

    int m = median(v);
    printf("median: %d\n", m);

    vector<double> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    double m2 = median(v2);
    printf("median: %f\n", m2);

    // big vector
    vector<int> v3;
    for (int i = 0; i < 1000000; i++)
    {
        v3.push_back(i);
    }

    time_from_last_call();
    int m3 = median(v3);
    printf("median: %d\n", m3);
    cout << "time: " << time_from_last_call().count() << endl;

    // in place
    time_from_last_call();
    int m4 = median_in_place<vector<int>::iterator, int>(v3.begin(), v3.end());
    printf("median: %d\n", m4);
    cout << "time: " << time_from_last_call().count() << endl;

    // random bigger one to test in place
    // test_big_vectors();

    return 0;
}
