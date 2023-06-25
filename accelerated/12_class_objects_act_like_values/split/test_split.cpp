// g++ test_split.cpp str.cpp -o test_split && ./test_split

#include <iostream>
#include "str.h"
#include "split.h"
#include <vector>
#include <list>
#include <cassert>

using namespace std;

int main()
{

    {
        // vector
        Str s = "this is a test";
        vector<Str> correct = {"this", "is", "a", "test"};

        vector<Str> v = split<vector<Str>>(s);
        for (vector<Str>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // list
        Str s = "this is a test";
        list<Str> correct = {"this", "is", "a", "test"};

        list<Str> l = split<list<Str>>(s);
        list<Str>::iterator it = l.begin();
        for (list<Str>::size_type i = 0; i != l.size(); ++i)
        {
            assert(*it == correct.front());
            correct.pop_front();
            ++it;
        }
    }

    return 0;
}
