// g++ -o bidirectional_it bidirectional_it.cpp && ./bidirectional_it

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end)
    {
        --end;
        if (begin != end)
            swap(*begin++, *end);
        // *begin++ = *end;
    }
}

int main()
{
    // built-in array
    int a[] = {1, 2, 3, 4, 5};
    reverse(a, a + 5);
    for (int i = 0; i < 5; ++i)
        cout << a[i] << " ";
    cout << endl;

    // vector
    vector<int> v(a, a + 5);
    reverse(v.begin(), v.end());
    for (int i = 0; i < 5; ++i)
        cout << v[i] << " ";
    cout << endl;

    // list
    list<int> l(a, a + 5);
    reverse(l.begin(), l.end());
    for (list<int>::iterator i = l.begin(); i != l.end(); ++i)
        cout << *i << " ";
    cout << endl;

    // string
    string s = "hello world";
    reverse(s.begin(), s.end());
    cout << s << endl;

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    reverse(vs.begin(), vs.end());
    for (vector<string>::iterator i = vs.begin(); i != vs.end(); ++i)
        cout << *i << " ";
    cout << endl;

    return 0;
}