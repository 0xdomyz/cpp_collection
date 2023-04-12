// g++ use_concepts.cpp -o use_concepts && ./use_concepts

// /usr/bin/gcc-11 -std=c++20 -o use_concepts use_concepts.cpp && ./use_concepts

// #Remove the previous alternatives
// sudo update-alternatives --remove-all gcc
// sudo update-alternatives --remove-all g++

// #Define the compiler
// sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 30
// sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 30

// sudo update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30
// sudo update-alternatives --set cc /usr/bin/gcc

// sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30
// sudo update-alternatives --set c++ /usr/bin/g++

// #Confirm and update (You can use the default setting)
// sudo update-alternatives --config gcc
// sudo update-alternatives --config g++

// g++ -std=c++20 -o use_concepts use_concepts.cpp && ./use_concepts

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

template <typename T>
constexpr bool Default_constructible()
{
    return requires { T{}; };
    // requires is a new keyword in C++20
}

int main(void)
{
    string s = "Hello";

    cout << Copy_equality(s) << endl;
    cout << Copy_assign_equality(s, s) << endl;

    return 0;
}
