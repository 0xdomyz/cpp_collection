// g++ array.cpp -o array && ./array

#include <iostream>
#include <cstddef>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // array
    const size_t NDim = 3;
    double coords[NDim];
    cout << *coords << endl;

    // pointer arithmetic
    vector<double> v;
    coords[0] = 1.0;
    coords[1] = 2.0;
    coords[2] = 3.0;
    copy(coords, coords + NDim, back_inserter(v));
    for (vector<double>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it;
    cout << endl;

    vector<double> v2(coords, coords + NDim);
    for (vector<double>::iterator it = v2.begin(); it != v2.end(); ++it)
        cout << *it;
    cout << endl;

    // array init
    const int month_lengths[] = {
        31, 28, 31, 30, 31, 30, // we will deal elsewhere with leap years
        31, 31, 30, 31, 30, 31};
    for (size_t i = 0; i != sizeof(month_lengths) / sizeof(*month_lengths); ++i)
        cout << month_lengths[i] << " ";
    cout << endl;

    // copy into coords
    double new_coords[] = {4.0, 5.0, 6.0};
    copy(new_coords, new_coords + NDim, coords);
    for (size_t i = 0; i != NDim; ++i)
        cout << coords[i] << " ";
    cout << endl;
}
