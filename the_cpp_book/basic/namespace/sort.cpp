// g++ sort.cpp -o sort && ./sort

#include <algorithm>
namespace Estd
{
    template <class C>
    void sort(C &c) { std::sort(c.begin(), c.end()); }

    template <class C, class P>
    void sort(C &c, P p) { std::sort(c.begin(), c.end(), p); }
}

#include <iostream>
#include <vector>

using namespace std;
using namespace Estd;

template <class T>
void print(const vector<T> &v)
{
    for (auto &x : v)
        cout << x << ' ';
    cout << '\n';
}

void f()
{
    std::vector<int> v{7, 3, 9, 4, 0, 1};
    sort(v);
    print(v);

    sort(v, [](int x, int y)
         { return x > y; });
    print(v);

    sort(v.begin(), v.end());
    print(v);

    sort(v.begin(), v.end(), [](int x, int y)
         { return x > y; });
    print(v);

    cout << "Hello World" << endl;
}

int main(void)
{
    f();
    return 0;
}