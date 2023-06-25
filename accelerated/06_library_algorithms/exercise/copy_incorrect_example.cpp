// g++ copy_incorrect_example.cpp -o copy_incorrect_example && ./copy_incorrect_example

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    vector<int>::size_type out_count = 0;
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        os << *it << " ";
        // output a line each 10 elements
        if (out_count != 0 && out_count % 10 == 0)
        {
            os << endl;
        }
        ++out_count;
    }
    return os;
}

int main(void)
{
    vector<int> u(20, 100);
    vector<int> v;

    // copy(u.begin(), u.end(), v.begin()); // segmentation fault

    // back_inserter
    copy(u.begin(), u.end(), back_inserter(v));

    // not use back_inserter
    // resize v to have as many elements as u
    // reserve means allocate memory, but not construct elements
    // resize means allocate memory and construct elements
    // v.resize(u.size());
    // cout << "v: " << v << endl;
    // copy(u.begin(), u.end(), v.begin());

    cout << "u: " << u << endl;
    cout << "v: " << v << endl;
}