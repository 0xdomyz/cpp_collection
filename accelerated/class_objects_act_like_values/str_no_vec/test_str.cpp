// g++ test_str.cpp str.cpp -o test_str && ./test_str

#include <iostream>
#include "str.h"
#include <cassert>
#include <cstring>

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

        cout << endl;
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
}
