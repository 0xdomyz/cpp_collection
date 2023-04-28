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

// char literal notation
char v1[] = "a\xah\129";  // 6 chars: 'a' '\xa' 'h' '\12' '9' '\0'
char v2[] = "a\xah\127";  // 5 chars: 'a' '\xa' 'h' '\127' '\0'
char v3[] = "a\xad\127";  // 4 chars: 'a' '\xad' '\127' '\0'
char v4[] = "a\xad\0127"; // 5 chars: 'a' '\xad' '\012' '7' '\0

int main()
{
    digits();
    cout << '\n';

    cout << "v1: " << v1 << '\n';
    cout << "v2: " << v2 << '\n';
    cout << "v3: " << v3 << '\n';
    cout << "v4: " << v4 << '\n';
    cout << endl;

    // conversion between char, signed char, and unsigned char
    signed char sc = -160;

    unsigned char uc = sc;        // uc == 116 (because 256-160==116)
    cout << sc << " " << int(sc); // print
    cout << uc << " " << int(uc); // print 't'

    char count[256]; // assume 8-bit chars
    // ++count[sc];     // likely disaster: out-of-range access
    ++count[uc]; // OK
    cout << endl;

    intval();
}