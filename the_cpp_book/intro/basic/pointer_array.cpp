// g++ -o pointer_array pointer_array.cpp -std=c++11 && ./pointer_array

#include <iostream>
using namespace std;

void copy_fct()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];                    // to become a copy of v1
    for (auto i = 0; i != 10; ++i) // copy elements
        v2[i] = v1[i];
    // ...
}

void print()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto x : v) // for each x in v
        cout << x << '\n';
    for (auto x : {10, 21, 32, 43, 54, 65})
        cout << x << '\n';
    // ...
}

void increment()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &x : v)
        ++x;
    // ...
}

int count_x(char *p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
{
    if (p == nullptr)
        return 0;
    int count = 0;
    for (; *p != 0; ++p)
        if (*p == x)
            ++count;
    return count;
}

int main()
{
    copy_fct();
    print();
    increment();
    char p[] = "Hello, world!";
    cout << count_x(p, 'l') << '\n';
}