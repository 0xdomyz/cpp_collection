// g++ test_str.cpp -o test_str && ./test_str

#include <iostream>
#include "str.h"
// #include "str_no_vec.h"

using namespace std;

int main(void)
{
    Str s = "hello";
    cout << s << endl;

    // indexing
    cout << s[0] << endl;

    {
        cout << "conversions" << endl;
        double d = 10; // convert 10 to double and use the converted value to initialize d
        double d2;
        d2 = 10; // convert 10 to double and assign the converted value to d

        Str s("hello"); // construct s

        Str t = "hello"; // initialize t
        s = "hello";     // assign a new value to s

        cout << endl;
    }

    {
        cout << "concatenation of Str objects and C-style strings" << endl;
        Str s = "hello";
        Str t = "1" + s + " abc";
        cout << t << endl;

        cout << endl;
    }

    {
        cout << "c_str()" << endl;
        Str s = "hello";
        cout << s.size() << endl;

        const char *c_str = s.c_str();
        while (*c_str)
        {
            cout << *c_str;
            ++c_str;
        }
        cout << endl;

        cout << s.c_str() << endl;

        s += " world";
        cout << s.c_str() << endl;

        cout << endl;
    }

    {
        cout << "data()" << endl;
        Str s = "hello";
        cout << s.size() << endl;

        const char *data = s.data();
        for (size_t i = 0; i < s.size(); ++i)
        {
            cout << data[i];
        }
        cout << endl;

        s += " world";

        const char *data2 = s.data();
        for (size_t i = 0; i < s.size(); ++i)
        {
            cout << data2[i];
        }
        cout << endl;
    }

    {
        cout << "copy()" << endl;
        Str s = "hello";

        {
            char *p = new char[s.size() + 1];
            s.copy(p, s.size());
            p[s.size()] = '\0';
            cout << p << endl;
            delete[] p;
        }

        {
            char *p = new char[3 + 1];
            s.copy(p, 3);
            p[3] = '\0';
            cout << p << endl;
            delete[] p;
        }
    }
}
