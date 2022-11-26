#include <iostream>

int get_value()
{
    return 3;
}

int main()
{
    int value = get_value();
    std::cout << "value : " << value << std::endl;
    return 0;
}