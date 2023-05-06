// g++ square_of_int.cpp -o square_of_int && ./square_of_int

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void)
{
    vector<double> ints;
    vector<double> squares;

    const int max_int = 100;

    for (auto i = 0; i < max_int; i++)
    {
        ints.push_back(i);
        squares.push_back(i * i);
    }

    cout << "ints"
         << "\t"
         << "squares" << endl;

    // display
    for (auto i = 0; i < max_int; i += 10)
    {
        // setw
        auto ss = setw(4);
        cout << ss << ints[i]
             << "\t"
             << ss << squares[i] << endl;
    }
}