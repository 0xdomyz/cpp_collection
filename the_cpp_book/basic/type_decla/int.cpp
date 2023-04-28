// g++ int.cpp -o int && ./int

#include <iostream>

using namespace std;

int main(void)
{
    // int literal suffix
    cout << 0xF0UL << ' ' << 0LU << '\n';

    // int litral hexadecimal
    cout << 0x0 << ' ' << 0x1 << ' ' << 0x2 << ' ' << 0x3 << '\n';
    cout << 0x4 << ' ' << 0x5 << ' ' << 0x6 << ' ' << 0x7 << '\n';
    cout << 0x8 << ' ' << 0x9 << ' ' << 0xA << ' ' << 0xB << '\n';
    cout << 0xC << ' ' << 0xD << ' ' << 0xE << ' ' << 0xF << '\n';

    // hexadecimal to represent bit patterns
    cout << 0xF << " = " << 0b1111 << '\n';
    cout << 0x5 << " = " << 0b0101 << '\n';
}
