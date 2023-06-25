// g++ -o input_it input_it.cpp && ./input_it

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "input_it.h"

using namespace std;

int main()
{
    // built-in array
    int a[] = {1, 2, 3, 4, 5};
    int *p = find(a, a + 5, 3);
    cout << *p << endl;

    // vector
    vector<int> v(a, a + 5);
    vector<int>::iterator it = find(v.begin(), v.end(), 3);
    cout << *it << endl;

    // list
    list<int> l(a, a + 5);
    list<int>::iterator it2 = find(l.begin(), l.end(), 3);
    cout << *it2 << endl;

    // string
    string s = "hello world";
    string::iterator it3 = find(s.begin(), s.end(), 'w');
    cout << *it3 << endl;

    // vector of strings
    vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    vector<string>::iterator it4 = find(vs.begin(), vs.end(), "world");
    cout << *it4 << endl;

    return 0;
}