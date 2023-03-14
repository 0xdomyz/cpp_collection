// Compile and run: g++ output.cpp -o output && ./output

#include <iostream>

using namespace std;

void f()
{
    cout << 10;
}

void g()
{
    int i{10};
    cout << i;
}

void h(int i)
{
    cout << "the value of i is ";
    cout << i;
    cout << '\n';
}

void h2(int i)
{
    cout << "the value of i is " << i << '\n';
}

void k()
{
    int b = 'b'; // note: char implicitly converted to int
    char c = 'c';
    cout << 'a' << b << c;
}

int main(void)
{
    f();
    g();
    h(10);
    h2(10);
    k();
}