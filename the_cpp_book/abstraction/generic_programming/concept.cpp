// g++ concept.cpp -o concept -std=c++2a && ./concept

#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool Copy_equality(T x) // semantics of copy constr uction
{
    return T{x} == x; // a copy compares equal to what it is a copy of
}

template <typename T>
bool Copy_assign_equality(T x, T &y) // semantics of assignment
{
    return (y = x, y == x); // the result of an assignment compares equal to the source of the assignment
}

// template <typename T>
// constexpr bool Default_constructible()
// {
//     return requires { T{}; };
//     // requires is a new keyword in C++20
// }

int main(void)
{
    string s = "Hello";

    cout << Copy_equality(s) << endl;
    cout << Copy_assign_equality(s, s) << endl;

    return 0;
}
