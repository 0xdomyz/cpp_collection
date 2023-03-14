// Compile and run: g++ input.cpp -o input && ./input

#include <iostream>

using namespace std;

void f()
{
    int i;
    cin >> i; // read an integer into i
    double d;
    cin >> d; // read a double-precision floating-point number into d
}

void hello()
{
    cout << "Please enter your name\n";
    string str;
    cin >> str;
    cout << "Hello, " << str << "!\n";
}

void hello_line()
{
    cout << "Please enter your name\n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
}

int main(void)
{
    f();
    hello();
    cout << "------------------" << endl;
    hello_line();
}