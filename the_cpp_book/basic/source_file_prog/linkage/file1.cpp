#include <iostream>

using namespace std;

// int a() { return f() + 7; } // error : f() not (yet) declared, also x

int x = 1;

int b = 2;

int f()
{ /* do something */
    cout << "f() in file1.cpp" << endl;
    return 0;
}

static int x1 = 1;   // internal linkage: not accessible from other translation units
const char x2 = 'a'; // internal linkage: not accessible from other translation units

int x3 = 1;                 // exter nal linkage: accessible from other translation units
extern const char x4 = 'a'; // exter nal linkage: accessible from other translation units

#include "h.h"
int h(int i)
{
    return next(i);
} // fine

using T = int;
const int x7 = 7;
constexpr T c2 = x7 + 1;

extern const int a = 77;
