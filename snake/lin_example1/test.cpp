#include <iostream>

struct Snake
{
    int x, y;
} s[100];

int x, y = 3;

int main()
{
    std::cout << " " << std::endl;
    std::cout << s[0].x << std::endl;
    std::cout << s[0].y << std::endl;
    std::cout << s[1].x << std::endl;
    std::cout << s[1].y << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}
