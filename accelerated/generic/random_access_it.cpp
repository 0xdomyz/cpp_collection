// g++ -o random_access_it random_access_it.cpp && ./random_access_it

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

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