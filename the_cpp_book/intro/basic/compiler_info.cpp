// g++ compiler_info.cpp -std=c++11 -o compiler_info && ./compiler_info
// g++ compiler_info.cpp -o compiler_info && ./compiler_info

// check value of __cplusplus
#include <iostream>

int main()
{
    std::cout << "__cplusplus = " << __cplusplus << std::endl;
}