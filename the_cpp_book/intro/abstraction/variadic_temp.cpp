// g++ -o variadic_temp variadic_temp.cpp && ./variadic_temp

#include <iostream>

using namespace std;

// prototypes
template <typename T>
void g(T x);

void f();

// variadic template
template <typename T, typename... Tail>
void f(T head, Tail... tail)
{
    g(head);    // do something to head
    f(tail...); // tr y again with tail
}

// base case
void f() {} // do nothing

// g() is a template function
template <typename T>
void g(T x)
{
    cout << x << " ";
}

int main()
{
    cout << "first: ";
    f(1, 2.2, "hello");
    cout << "\nsecond: ";
    f(0.2, 'c', "yuck!", 0, 1, 2);
    cout << "\n";
}