// g++ median.cpp -o median && ./median

#include <algorithm>
#include <stdexcept>
#include <vector>

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
    vector<int> v = {1, 2, 3, 4, 5};
    int m = median(v);
    printf("median: %d\n", m);

    vector<double> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    double m2 = median(v2);
    printf("median: %f\n", m2);

    return 0;
}
