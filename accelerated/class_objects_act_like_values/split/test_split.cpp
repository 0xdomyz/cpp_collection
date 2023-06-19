// g++ test_split.cpp -o test_split && ./test_split

#include <iostream>
#include <string>
#include "split.h"
#include <vector>
#include <list>
#include <cassert>

using namespace std;

int main()
{

    {
        // vector
        string s = "this is a test";
        vector<string> correct = {"this", "is", "a", "test"};

        vector<string> v = split<vector<string>>(s);
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // list
        string s = "this is a test";
        list<string> correct = {"this", "is", "a", "test"};

        list<string> l = split<list<string>>(s);
        list<string>::iterator it = l.begin();
        for (list<string>::size_type i = 0; i != l.size(); ++i)
        {
            assert(*it == correct.front());
            correct.pop_front();
            ++it;
        }
    }

    return 0;
}
