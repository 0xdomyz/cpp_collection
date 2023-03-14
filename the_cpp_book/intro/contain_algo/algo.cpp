// Compile object file: g++ -c entry.cpp
// Compile: g++ algo.cpp entry.o -o algo
// run: ./algo

// above in 1 line: g++ algo.cpp entry.cpp -o algo && ./algo

#include "entry.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}};

    for (const auto &x : phone_book)
        std::cout << x << std::endl;

    return 0;
}