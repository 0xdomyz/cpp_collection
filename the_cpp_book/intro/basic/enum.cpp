// g++ -std=c++11 -o enum enum.cpp && ./enum

#include <iostream>

enum class Color
{
    red,
    blue,
    green
};
enum class Traffic_light
{
    green,
    yellow,
    red
};

Traffic_light &operator++(Traffic_light &t)
// prefix increment: ++
{
    switch (t)
    {
    case Traffic_light::green:
        return t = Traffic_light::yellow;
    case Traffic_light::yellow:
        return t = Traffic_light::red;
    case Traffic_light::red:
        return t = Traffic_light::green;
    }
    return t;
}

int main()
{
    Traffic_light light = Traffic_light::green;
    std::cout << "light is green" << std::endl;

    Traffic_light next = ++light; // next becomes Traffic_light::yellow
    if (next == Traffic_light::red)
        std::cout << "next is red" << std::endl;
    else
        std::cout << "next is not red" << std::endl;
}