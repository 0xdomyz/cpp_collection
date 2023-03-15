// Compile and run: g++ container_algo.cpp -o container_algo && ./container_algo

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace Estd
{
    using namespace std;
    template <class C>
    void sort(C &c)
    {
        sort(c.begin(), c.end());
    }
    template <class C, class Pred>
    void sort(C &c, Pred p)
    {
        sort(c.begin(), c.end(), p);
    }
    // ...
}

int main(void)
{
    vector<int> v{47, 25, 64, 1, 12, 3, 71, 8, 9};
    cout << "v.size() = " << v.size() << endl;

    cout << "original:" << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    Estd::sort(v);
    cout << "sorted:" << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    Estd::sort(v, [](int a, int b)
               { return a > b; });
    cout << "sorted descending:" << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}