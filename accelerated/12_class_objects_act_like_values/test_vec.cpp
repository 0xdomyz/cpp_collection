// g++ test_vec.cpp str.cpp -o test_vec && ./test_vec

#include <iostream>
#include "vec.h"
#include "str.h"
#include <cassert>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{

    {
        // insert on vec
        Str s = "hello";
        Vec<char> v(s.begin(), s.end());
        Str t = " world adasfdasfasdfdsadsfadsfasewfewfsfdasfdasgfasasdaf";

        v.insert(v.end(), t.begin(), t.end());

        Str correct = s + t;
        for (Vec<char>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // insert on vec front
        Str s = "hello";
        Vec<char> v(s.begin(), s.end());
        Str t = " world";

        v.insert(v.begin(), t.begin(), t.end());

        Str correct = t + s;
        for (Vec<char>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // insert on vec middle
        Str s = "hello";
        Vec<char> v(s.begin(), s.end());
        Str t = " world";

        v.insert(v.begin() + 2, t.begin(), t.end());

        Str correct = "he" + t + "llo";
        for (Vec<char>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // assign
        Str s = "hello";
        Vec<char> v(s.begin(), s.end());
        Str correct = "world";

        v.assign({'w', 'o', 'r', 'l', 'd'});

        for (Vec<char>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }

    {
        // vec from string
        string s = "hello";
        Vec<char> v(s.begin(), s.end());
        Str correct = "hello";
        for (Vec<char>::size_type i = 0; i != v.size(); ++i)
        {
            assert(v[i] == correct[i]);
        }
    }
}
