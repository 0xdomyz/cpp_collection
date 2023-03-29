// Compile and run: g++ delegating_constructors.cpp -o delegating_constructors && ./delegating_constructors

#include <iostream>
#include <string>

using namespace std;

class Bad_X
{
    int x;

public:
    Bad_X(int x) : x{x} {}
    int bad() const { return x; }
};

class X
{
    int max = 100;
    int a;
    void validate(int x)
    {
        if (0 < x && x <= max)
            a = x;
        else
            throw Bad_X(x);
    }

public:
    X(int x) { validate(x); }
    X() { validate(42); }
    // X(string s)
    // {
    //     int x = static_cast<int>(s);
    //     validate(x);
    // } // §25.2.5.1
    // ...
};

class X2
{
    int a;
    int max = 100;

public:
    X2(int x)
    {
        if (0 < x && x <= max)
            a = x;
        else
            throw Bad_X(x);
    }
    X2() : X2{42} {}
    // X2(string s) : X2{to<int>(s)} {} // §25.2.5.1
    // ...
};

class X3
{
    int a;
    int max = 100;

public:
    X3(int x)
    {
        if (0 < x && x <= max)
            a = x;
        else
            throw Bad_X(x);
    }
    // X3() : X3{42}, a{56} {} // error
    // ...
};

class X4
{
    int a;
    int max = 100;

public:
    X4(int x)
    {
        if (0 < x && x <= max)
            a = x;
        else
            throw Bad_X(x);
    }
    X4() { X4{42}; } // likely error
    // ...
};

int main(void)
{
    X x1;
    X x2{99};
    // X x3{"99"}; // §
}