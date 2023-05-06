// g++ test_streamsize.cpp -o test_streamsize && ./test_streamsize

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{

    double numbers[] = {1.23456789, 2.3456789, 3.456789, 4.56789, 5.6789};
    double large_numbers[] = {123456789.123456789, 23456789.23456789, 3456789.3456789, 456789.456789, 56789.56789};
    string names[] = {"one", "two", "three", "four", "five"};

    // cout
    for (auto i = 0; i < 5; i++)
    {
        cout << numbers[i] << endl;
    }
    for (auto i = 0; i < 5; i++)
    {
        cout << large_numbers[i] << endl;
    }

    // setw
    // it only works for the next output
    // padding is added from the left
    cout << "\nsetw" << endl;
    auto ss = setw(4);

    cout << ss << "aa" << endl;
    cout << "aa" << endl;

    cout << ss << 12 << endl;
    cout << 12 << endl;

    cout << ss << 123135423.3454 << endl;
    cout << 123135423.3454 << endl;

    cout << setw(4) << "aa"
         << " "
         << "a" << endl;

    // s.width()
    auto existing_size = cout.width();
    cout << "\nexisting_size: " << existing_size << endl;

    cout.width(4);
    cout << "aa" << endl;
    cout << "bb" << endl;

    cout.width(existing_size);
    cout << "aa" << endl;
    cout << "bb" << endl;

    // string placeholder
    cout << "\nstring placeholder" << endl;

    const string target = "asdf";
    streamsize maxlen = target.size() + 5; // from <iomanip>
    cout << string(maxlen + 1 - target.size(), ' ') << target << endl;

    // precision
    cout << "\nprecision" << endl;
    auto prec = cout.precision();
    cout << setprecision(3) << 123.456789 << endl;
    cout << setprecision(3) << 123.456789 << ' ' << 123.456789 << endl;
    cout << 123.456789 << endl;

    cout << setprecision(prec) << 123.456789 << endl;
    cout << 123.456789 << endl;
}
