// Compile and run: g++ initialization_using_constructors.cpp -o initialization_using_constructors && ./initialization_using_constructors

#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X(int)
    {
        cout << "X::X(int)" << endl;
    };
};
// X x0;        // error : no initializer
// X x1{};      // error : empty initializer
X x2{2}; // OK
// X x3{"two"}; // error : wrong initializer type
// X x4{1, 2};  // error : wrong number of initializers
X x4 = 4;
X x5{x4}; // OK: a copy constr uctor is implicitly defined (§17.6)

struct Y : X
{
    X m{0};                   // provide default initializer for member m
    Y(int a) : X{a}, m{a} {}; // initialize base and member (§17.4)
    Y() : X{0} {};            // initialize base and member
};
X g{1}; // initialize global var iable
void f(int a)
{
    // X def{}; // error : no default value for X
    Y de2{}; // OK: use default constructor
    X *p{nullptr};
    X var{2};                // initialize local var iable
    p = new X{4};            // initialize object on free store
    X a2[]{1, 2, 3};         // initialize array elements
    vector<X> v{1, 2, 3, 4}; // initialize vector elements
}

struct Y2 : X
{
    X m;
    // Y2(int a) : X(a), m = a{}; // syntax error: can’t use = for member initialization
};
X g2(1); // initialize global var iable
void f2(int a)
{
    X def(); // function returning an X (surpr ise!?)
    X *p{nullptr};
    X var = 2; // initialize local var iable
    // p = new X = 4;           // syntax error: can’t use = for new
    // X a[](1, 2, 3);          // error : can’t use () for array initialization
    // vector<X> v(1, 2, 3, 4); // error : can’t use () for list elements
}

struct S
{
    S(const char *)
    {
        cout << "S::S(const char*)" << endl;
    };
    S(double *)
    {
        cout << "S::S(double*)" << endl;
    };
};
S s1{"Napier"};        // S::S(const char*)
S s2{new double{1.0}}; // S::S(double*);
// S s3{nullptr};         // ambiguous: S::S(const char*) or S::S(double*)?

int main(void)
{
    return 0;
}