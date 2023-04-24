#include "error.h"

int Error::no_of_errors;
double Error::error(const std::string &s)
{

    no_of_errors++;
    std::cerr << "error: " << s << '\n'; // cerr from <iostream>
    return 1;
}