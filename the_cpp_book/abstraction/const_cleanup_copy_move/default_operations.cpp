// Compile and run: g++ default_operations.cpp -o default_operations && ./default_operations

#include <iostream>
#include <string>

using namespace std;

struct S
{
    string a;
    int b;
};
S f(S arg)
{
    S s0{};    // default construction: {"",0}
    S s1{s0};  // copy constr uction
    s1 = arg;  // copy assignment
    return s1; // move constr uction
}

int main(void)
{
    S s2{};
    s2 = f({string{"abc"}, 1}); // move assignment
    return 0;
}