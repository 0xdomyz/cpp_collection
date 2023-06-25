// g++ -o test_split test_split.cpp split.cpp && echo "asdf asdf rv 4 fv 4t " | ./test_split

#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using namespace std;

int main()
{
    string s;
    // read and split each line of input
    while (getline(cin, s))
    {
        vector<string> v = split(s);
        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}