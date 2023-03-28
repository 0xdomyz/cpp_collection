// Compile and run: g++ constructors_and_destructors.cpp -o constructors_and_destructors && ./constructors_and_destructors

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tracer
{
    string mess;
    Tracer(const string &s) : mess{s} { clog << mess; }
    ~Tracer() { clog << "~" << mess; }
};
void f(const vector<int> &v)
{
    Tracer tr{"in f()\n"};
    for (auto x : v)
    {
        string x_str = to_string(x);
        Tracer tr{string{"v loop "} + x_str + '\n'}; // §25.2.5.1
        // ...
    }
}

int main(void)
{
    f({2, 3, 5});
}