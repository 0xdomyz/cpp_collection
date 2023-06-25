// g++ test_str.cpp str.cpp -o test_str && echo "hello world" | ./test_str

#include <iostream>
#include "str.h"
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    {
        // basic
        Str s = "hello";

        // indexing
        const char *correct = "hello";
        for (Str::size_type i = 0; i != s.size(); ++i)
            assert(s[i] == correct[i]);
    }

    {
        // conversions
        double d = 10; // convert 10 to double and use the converted value to initialize d
        double d2;
        d2 = 10; // convert 10 to double and assign the converted value to d

        Str s("hello"); // construct s

        Str t = "hello"; // initialize t
        s = "hello";     // assign a new value to s
    }

    {
        // concatenation of Str objects and C-style strings
        Str s = "hello";
        Str t = "1" + s + " abc";
        const char *correct = "1hello abc";
        for (Str::size_type i = 0; i != t.size(); ++i)
            assert(t[i] == correct[i]);
    }

    {
        // c_str()
        Str s = "hello";
        assert(s.size() == 5);

        const char *c_str = s.c_str();
        const char *correct = "hello";
        while (*c_str)
        {
            assert(*c_str == *correct);
            ++c_str;
            ++correct;
        }

        s += " world";
        const char *correct2 = "hello world";
        assert(strcmp(s.c_str(), correct2) == 0);
    }

    {
        // data()
        Str s = "hello";
        assert(s.size() == 5);

        const char *data = s.data();
        const char *correct = "hello";
        for (size_t i = 0; i < s.size(); ++i)
        {
            assert(data[i] == correct[i]);
        }

        s += " world";

        const char *data2 = s.data();
        const char *correct2 = "hello world";
        for (size_t i = 0; i < s.size(); ++i)
        {
            assert(data2[i] == correct2[i]);
        }
    }

    {
        // copy()
        Str s = "hello";

        {
            char *p = new char[s.size() + 1];
            s.copy(p, s.size());
            p[s.size()] = '\0';

            const char *correct = "hello";
            assert(strcmp(p, correct) == 0);

            delete[] p;
        }

        {
            char *p = new char[3 + 1];
            s.copy(p, 3);
            p[3] = '\0';

            const char *correct = "hel";
            assert(strcmp(p, correct) == 0);

            delete[] p;
        }
    }

    {
        // operator==
        Str s = "hello world";
        Str t = "hello world";
        Str u = "helasdfloasdf";
        assert(s == t);
        assert(!(s == u));
    }

    {
        // relations
        Str small = "helloa";
        Str mid = "hellog";
        Str big = "helloz";

        assert(small < mid);
        assert(!(small > mid));

        assert(big > mid);
        assert(small <= mid);
        assert(big >= mid);
        assert(small <= small);
        assert(small >= small);

        // equality and inequality
        assert(small != big);
        assert(small == small);
    }

    {
        // use in condition
        Str s = "hello";
        Str t;

        assert(s);
        if (s)
            assert(true);
        else
            assert(false);

        if (t)
            assert(false);
        else
            assert(true);
    }

    {
        // begin and end
        Str s = "hello";
        const char *correct = "hello";
        for (Str::iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            assert(*iter == *correct);
            ++correct;
        }

        // random access
        correct = "hello";
        for (Str::size_type i = 0; i != s.size(); ++i)
        {
            assert(s[i] == correct[i]);
        }
    }

    {
        // getline
        Str s;
        s.getline(cin);
        assert(s == Str("hello world"));
    }

    {
        // output stream
        Str s = "hello world";
        cout << "should be hello world: " << s << endl;
    }

    {
        // insert
        Str s = "hello";
        Str t = " world";
        Str::size_type pos = 2;
        Str correct = "he worldllo";
        s.insert(s.begin() + pos, t.begin(), t.end());
        assert(s == correct);
    }

    {
        // insert vec
        Str s = "hello";
        Vec<char> v;
        for (Str::size_type i = 0; i != 5; ++i)
            v.push_back('a' + i);
        Str correct = "helloabcde";
        s.insert(s.end(), v.begin(), v.end());
        assert(s == correct);
    }

    {
        // assign
        Str s = "hello";
        Str correct = "world";
        s.assign({'w', 'o', 'r', 'l', 'd'});
        assert(s == correct);
    }
}
