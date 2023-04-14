// g++ shell_sort.cpp -o shell_sort && ./shell_sort

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

namespace shell_sort
{
    template <typename T>
    bool less(T a, T b)
    {
        return a < b;
    };

    template <>
    bool less(const char *a, const char *b)
    {
        return strcmp(a, b) < 0;
    }

    template <typename T>
    void sort(vector<T> &v)
    {
        const size_t n = v.size();
        for (int gap = n / 2; 0 < gap; gap /= 2)
            for (int i = gap; i != n; ++i)
                for (int j = i - gap; 0 <= j; j -= gap)
                    if (less(v[j + gap], v[j]))
                        swap(v[j], v[j + gap]);
    };
};

int main(void)
{
    vector<int> v = {1, 3, 2, 5, 4};
    shell_sort::sort(v);
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    vector<const char *> c = {"hello", "world", "this", "is", "a", "test"};
    shell_sort::sort(c);
    for (auto i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}