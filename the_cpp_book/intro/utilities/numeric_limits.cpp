// Compile and run: g++ numeric_limits.cpp -o numeric_limits && ./numeric_limits

#include <limits>
#include <iostream>

using namespace std;

int main(void)
{
    static_assert(numeric_limits<char>::is_signed, "unsigned characters!");
    static_assert(100000 < numeric_limits<int>::max(), "small ints!");

    cout << "max char: " << numeric_limits<char>::max() << '\n';
    cout << "max int: " << numeric_limits<int>::max() << '\n';
}