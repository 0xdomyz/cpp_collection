// g++ square_of_int.cpp -o square_of_int && ./square_of_int 100
// g++ square_of_int.cpp -o square_of_int && ./square_of_int 999

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// allow cmd args
int main(int argc, char *argv[])
{
    vector<int> ints;
    vector<int> squares;

    const int max_int = argv[1] ? atoi(argv[1]) : 100;
    cout << "max_int: " << max_int << endl;

    for (auto i = 0; i < max_int; i++)
    {
        ints.push_back(i);
        squares.push_back(i * i);
    }

    cout << "ints"
         << "\t"
         << "squares" << endl;

    // display
    const string max_int_str = to_string(ints[max_int - 1]);
    const auto max_int_width = max_int_str.size();
    cout << "max_int_str: " << max_int_str << endl;

    const string max_sqr_str = to_string(squares[max_int - 1]);
    const auto max_width = max_sqr_str.size();
    cout << "max_sqr_str: " << max_sqr_str << endl;

    for (auto i = 0; i < max_int; i += max_int / 10)
    {
        // setw
        cout << setw(max_int_width) << ints[i]
             << "\t"
             << setw(max_width) << squares[i] << endl;
    }
}