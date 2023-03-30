// Compile and run: g++ initialization_by_constructors.cpp -o initialization_by_constructors && ./initialization_by_constructors

#include <iostream>
#include <vector>

using namespace std;

struct S1
{
    int a, b; // no constructor
};

struct S2
{
    int a, b;
    S2(int aa = 0, int bb = 0) : a(aa), b(bb) {} // constructor
};
// S1 x11(1, 2); // error : no constructor
S1 x12{1, 2}; // OK: memberwise initialization
// S1 x13(1);    // error : no constructor
S1 x14{1};    // OK: x14.b becomes 0
S2 x21(1, 2); // OK: use constructor
S2 x22{1, 2}; // OK: use constructor
S2 x23(1);    // OK: use constructor and one default argument
S2 x24{1};    // OK: use constructor and one default argument

vector<int> v1{77}; // one element with the value 77
vector<int> v2(77); // 77 elements with the default value 0

vector<string> v11{77}; // 77 elements with the default value ""
// (vector<str ing>(std::initializer_list<str ing>) doesn’t accept {77})
vector<string> v12(77);      // 77 elements with the default value ""
vector<string> v13{"Booh!"}; // one element with the value "Booh!"
// vector<string> v4("Booh!"); // error : no constructor takes a string argument
vector<int *> v5{100, 0}; // 100 int*s initialized to nullptr (100 is not an int*)
vector<int *> v51{10, 0};
vector<int *> v52(10, 0);
vector<int *> v6{0, 0}; // 2 int*s initialized to nullptr
vector<int *> v7(0, 0); // empty vector (v7.size()==0)
vector<int *> v8;       // empty vector (v7.size()==0)

int main(void)
{
    for (auto x : v52)
        cout << x << "\n";
    return 0;
}
