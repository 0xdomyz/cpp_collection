// Compile and run: g++ math_functions_algos.cpp -o math_functions_algos && ./math_functions_algos

#include <iostream>
#include <cmath>
#include <list>
#include <numeric>

using namespace std;

void f()
{
    list<double> lst{1, 2, 3, 4, 5, 9999.99999};
    auto s = accumulate(lst.begin(), lst.end(), 0.0); // calculate the sum
    // 4 decimla places, not scientific notation
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(10);
    cout << s << '\n'; // print 10014.9999
    // revert
    cout.unsetf(ios_base::floatfield);
}

int main(void)
{
    f();
}