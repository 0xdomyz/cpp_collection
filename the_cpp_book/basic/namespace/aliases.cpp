// g++ aliases.cpp -o aliases && ./aliases

#include <iostream>
#include <string>

namespace A
{ // shor t name, will clash (eventually)
    // ...
    using String = std::string;
}

A::String s1 = "Grieg";
A::String s2 = "Nielsen";

namespace American_Telephone_and_Telegraph
{ // too long
    // ...
    using String = std::string;
}
American_Telephone_and_Telegraph::String s3 = "Grieg";
American_Telephone_and_Telegraph::String s4 = "Nielsen";

// use namespace alias to shorten names:
namespace ATT = American_Telephone_and_Telegraph;
ATT::String s5 = "Grieg";
ATT::String s6 = "Nielsen";

int main(void) {}
