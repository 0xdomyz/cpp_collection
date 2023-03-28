// Compile and run: g++ base_and_member_destructors.cpp -o base_and_member_destructors && ./base_and_member_destructors

#include <string>

using namespace std;

struct S1
{
    string s;
};
S1 x; // OK: x.s is initialized to ""

struct X
{
    X(int){};
};
struct S2
{
    X x;
};
// S2 x1;    // error :
S2 x2{1}; // OK: x2.x is initialized with 1

int main(void)
{
    return 0;
}