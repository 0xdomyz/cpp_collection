// g++ -o random_access_it random_access_it.cpp && ./random_access_it

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class Ran, class X>
bool custom_binary_search(Ran begin, Ran end, const X &x)
{
    while (begin < end)
    {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking only in that part
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        // if we got here, then *mid == x so we're done
        else
            return true;
    }
    return false;
}

int main()
{
    // built-in array
    int a[] = {1, 2, 3, 4, 5};
    sort(a, a + 5);
    cout << custom_binary_search(a, a + 5, 3) << endl;

    // vector
    vector<int> v(a, a + 5);
    sort(v.begin(), v.end());
    cout << custom_binary_search(v.begin(), v.end(), 3) << endl;

    // list
    list<int> l(a, a + 5);
    l.sort();
    cout << binary_search(l.begin(), l.end(), 3) << endl; // binary_search is a built-in function

    // string
    string s = "hello world";
    sort(s.begin(), s.end());
    cout << binary_search(s.begin(), s.end(), 'e') << endl;

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    sort(vs.begin(), vs.end());
    cout << binary_search(vs.begin(), vs.end(), "hello") << endl;
    cout << binary_search(vs.begin(), vs.end(), "goodbye") << endl;

    return 0;
}