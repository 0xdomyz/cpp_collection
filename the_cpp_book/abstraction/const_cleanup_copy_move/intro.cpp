//  complie and run: g++ -o intro intro.cpp && ./intro

#include <iostream>
#include <string>

using namespace std;

string ident(string arg) // string passed by value (copied into arg)
{
    return arg; // return str ing (move the value of arg out of ident() to a caller)
}
int main()
{
    string s1{"Adams"}; // initialize str ing (constr uct in s1).
    s1 = ident(s1);     // copy s1 into ident()
    // move the result of ident(s1) into s1;
    // s1’s value is "Adams".
    string s2{"Pratchett"}; // initialize str ing (constr uct in s2)
    s1 = s2;                // copy the value of s2 into s1
    // both s1 and s2 have the value "Pratchett".
    cout << s1 << endl;
    cout << s2 << endl;
}