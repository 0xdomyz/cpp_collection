// compile file1 and file2 with the following command:
// g++ -c file1.cpp file2.cpp
// link: g++ file1.o file2.o -o file
// run: ./file
// all together:
// g++ -c file1.cpp file2.cpp && g++ file1.o file2.o -o file && ./file

#include <iostream>

using namespace std;

extern int x;

// extern double b;

int f(); // defined in file1.cpp

void g()
{
    x = f();
    cout << "g() in file2.cpp" << endl;
}

int h(int i);

#include "h.h"
int b(int i)
{
    return next(i);
} // fine

using T = double;
const int x7 = 8;
constexpr T c2 = x7 + 9;

extern const int a;

int main(void)
{
    g();
    cout << "h(1) = " << h(1) << endl;
    cout << "b(1) = " << b(1) << endl;
    cout << "a = " << a << endl;
    return 0;
}
