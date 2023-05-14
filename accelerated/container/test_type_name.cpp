// g++ test_type_name.cpp -o test_type_name -std=c++17 && ./test_type_name

#include <iostream>
#include "type_name.h"

using namespace std;

int main(void)
{

    const int ci = 0;
    std::cout << type_name<decltype(ci)>() << '\n';
}
