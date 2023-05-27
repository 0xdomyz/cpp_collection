// g++ split.cpp test_split.cpp -o test_split && ./test_split

#include <iostream>
#include <vector>
#include <string>
#include "split.h"

using namespace std;

int main(void)
{
    vector<string> v = split("the quick brown fox jumps over the lazy dog");
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;
}