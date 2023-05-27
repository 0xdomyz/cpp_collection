// g++ return_type.cpp -o return_type && ./return_type

#include <vector>

std::vector<double> f()
{
    return {1, 2, 3, 4, 5};
}

int main(void)
{
    int n = 0;
    double d = f()[n];
}