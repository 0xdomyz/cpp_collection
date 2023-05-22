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
    replace(a, a + 5, 3, 0);
    for (int i = 0; i < 5; ++i)
        cout << a[i] << " ";
    cout << endl;

    // vector
    vector<int> v(a, a + 5);
    replace(v.begin(), v.end(), 3, 0);
    for (int i = 0; i < 5; ++i)
        cout << v[i] << " ";
    cout << endl;

    // list
    list<int> l(a, a + 5);
    replace(l.begin(), l.end(), 3, 0);
    for (list<int>::iterator i = l.begin(); i != l.end(); ++i)
        cout << *i << " ";
    cout << endl;

    // string
    string s = "hello world";
    replace(s.begin(), s.end(), 'l', 'L');
    cout << s << endl;

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    replace(vs.begin(), vs.end(), string("hello"), string("HELLO"));
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << " ";
    cout << endl;

    return 0;
}