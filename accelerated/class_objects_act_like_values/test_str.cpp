// g++ test_str.cpp -o test_str && ./test_str

#include <iostream>
// #include "str.h"
#include "str_no_vec.h"

using namespace std;

int main(void)
{
    Str s = "hello";
    cout << s << endl;

    // indexing
    cout << s[0] << endl;

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
        cout << t << endl;
    }
}
