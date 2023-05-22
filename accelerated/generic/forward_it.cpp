// g++ -o forward_it forward_it.cpp && ./forward_it

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class For, class X>
void replace(For beg, For end, const X &x, const X &y)
{
    while (beg != end)
    {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

int main()
{
    // built-in array
    int a[] = {1, 2, 3, 4, 5};

    // vector
    vector<int> v(a, a + 5);

    // list
    list<int> l(a, a + 5);

    // string
    string s = "hello world";

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");

    return 0;
}