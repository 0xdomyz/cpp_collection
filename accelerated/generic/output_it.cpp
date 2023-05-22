// g++ -o output_it output_it.cpp && ./output_it

#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::back_inserter;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

template <class In, class Out>
Out custom_copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

int main()
{
    // built-in array
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    int *p2 = a + 5;
    int b[5];
    int *p3 = b;
    custom_copy(p, p2, p3);
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    // vector
    vector<int> v(a, a + 5);
    vector<int>::iterator it = v.begin();
    vector<int>::iterator it2 = v.end();
    vector<int> v2;
    auto it3 = back_inserter(v2);
    custom_copy(it, it2, it3);
    for (int i = 0; i < 5; ++i)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    // list
    list<int> l(a, a + 5);
    list<int>::iterator it4 = l.begin();
    list<int>::iterator it5 = l.end();
    list<int> l2;
    auto it6 = back_inserter(l2);
    custom_copy(it4, it5, it6);
    for (auto i : l2)
    {
        cout << i << " ";
    }
    cout << endl;

    // string
    string s = "hello world";
    string::iterator it7 = s.begin();
    string::iterator it8 = s.end();
    string s2;
    auto it9 = back_inserter(s2);
    custom_copy(it7, it8, it9);
    cout << s2 << endl;

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    vector<string>::iterator it10 = vs.begin();
    vector<string>::iterator it11 = vs.end();
    vector<string> vs2;
    auto it12 = back_inserter(vs2);
    custom_copy(it10, it11, it12);
    for (auto i : vs2)
        cout << i << endl;

    return 0;
}