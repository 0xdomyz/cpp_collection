#include "dc.h"
// any more #includes or declarations

int Error::no_of_errors;
double Error::error(const string &s)
{

    no_of_errors++;
    std::cerr << "error: " << s << '\n'; // cerr from <iostream>
    return 1;
}