// g++ type_func.cpp -o type_func -std=c++11 && ./type_func

#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

enum class Axis : char
{
    x,
    y,
    z
};

enum flags
{
    off,
    x = 1,
    y = x << 1,
    z = x << 2,
    t = x << 3
};

int main(void)
{
    if (is_polymorphic<int>::value)
        cout << "Big surprise!";
    typename std::underlying_type<Axis>::type x; // x is a char
    typename std::underlying_type<Axis>::type y; // y is probably an int (§8.4.2)
};