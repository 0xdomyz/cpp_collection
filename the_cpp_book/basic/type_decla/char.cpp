// g++ -std=c++17 -o char char.cpp && ./char

#include <iostream>

using namespace std;

// convert keyboard characters to their integer values
void intval()
{
    for (char c; cin >> c;)
        cout << "the value of '" << c << "' is " << int{c} << '\n';
}

// arithmetic with characters
void digits()
{
    for (int i = 0; i != 10; ++i)
        cout << static_cast<char>('0' + i) << ' ';

    cout << '\n';

    // no cast
    for (int i = 0; i != 10; ++i)
        cout << '0' + i << ' ';
}

int main()
{
    digits();
    cout << '\n';
    intval();
}