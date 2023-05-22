// g++ -o test_split test_split.cpp && echo "aaa ccc bbb ddd 23 " | ./test_split

#include <iostream>
#include <iterator>
#include <string>
#include "split.h"

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
        split(s, ostream_iterator<string>(cout, "\n"));
    // ;
    return 0;
}
