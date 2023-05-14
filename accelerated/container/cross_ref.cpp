// g++ urls.cpp split.cpp cross_ref.cpp -o cross_ref -std=c++20 && ./cross_ref

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "split.h"
#include "urls.h"

using namespace std;

int main(void)
{
    const string s = "This is a test string";
    vector<string> v = split(s);
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }

    const string s2 = "This is a https://adsf test str://ing";
    vector<string> v2 = find_urls(s2);
    for (vector<string>::const_iterator i = v2.begin(); i != v2.end(); ++i)
    {
        cout << *i << endl;
    }
}
