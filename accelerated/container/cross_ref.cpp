// g++ split.cpp cross_ref.cpp -o cross_ref -std=c++20 && ./cross_ref

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "split.h"

using namespace std;

int main(void)
{
    const string s = "This is a test string";
    vector<string> v = split(s);
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }
}
