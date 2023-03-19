// g++ initializer_list.cpp -o initializer_list && ./initializer_list

#include <iostream>
#include <initializer_list>

using namespace std;

void f(initializer_list<int> lst)
{
    // for (int i = 0; i < lst.size(); ++i)
    //     cout << lst[i] << '\n'; // error
    const int *p = lst.begin();
    for (int i = 0; i < lst.size(); ++i)
        cout << p[i] << '\n'; // OK
}

void f2(initializer_list<int> lst)
{
    for (auto x : lst)
        cout << x << '\n';
}

int main()
{
    f({1, 2, 3, 4, 5});
    f2({1, 2, 3, 4, 5});
}