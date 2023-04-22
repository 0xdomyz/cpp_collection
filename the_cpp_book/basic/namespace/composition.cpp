// g++ composition.cpp -o composition && ./composition

#include <iostream>
#include <string>
#include <vector>

namespace His_string
{
    using String = std::string;
    void fill(char);
    // ...
}
namespace Her_vector
{
    template <class T>
    using Vector = std::vector<T>;
}

namespace My_lib
{
    using namespace His_string;
    using namespace Her_vector;
    void my_fct(String &);
}

void f()
{
    My_lib::String s = "Byron"; // finds My_lib::His_string::Str ing
    // ...
}
using namespace My_lib;
void g(Vector<String> &vs)
{
    // ...
    my_fct(vs[5]);
    // ...
}

// void My_lib::fill(char c) // error : no fill() declared in My_lib
// {
//     // ...
// }
void His_string::fill(char c) // OK: fill() declared in His_string
{
    // ...
}
void My_lib::my_fct(String &v) // OK: String is My_lib::String, meaning His_string::Str ing
{
    // ...
}

int main(void) {}