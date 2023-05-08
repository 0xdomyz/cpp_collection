// g++ split.cpp iter_of_vec_of_iter.cpp -o iter_of_vec_of_iter && cat permuted_test.csv | ./iter_of_vec_of_iter

#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include <algorithm>

using namespace std;

int main(void)
{

    string s;
    vector<string> v;
    while (getline(cin, s))
    {
        v = split(s);

        cout << "original" << endl;
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl;

        // rotate
        cout << "rotate" << endl;
        rotate(v.begin(), v.begin() + 1, v.end());
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            cout << *i << " ";
        }
        cout << endl;

        // copy iterator and use it
        auto j = v.begin() + 2;
        cout << "copy iterator" << endl;
        cout << *j << endl;
        vector<string>::const_iterator i = j;
        i = i + 1;
        cout << *i << endl;
        cout << *j << endl;

        vector<vector<string>::const_iterator> iters;
        iters.push_back(j);
        iters.push_back(i);

        cout << *iters[0] << endl;
        cout << *iters[1] << endl;

        cout << **iters.begin() << endl;
        cout << **(iters.begin() + 1) << endl;

        // store all iters of v into a vector
        vector<vector<string>::const_iterator> iters_of_v;
        for (auto i = v.begin(); i != v.end(); ++i)
        {
            iters_of_v.push_back(i);
        }
        cout << "iters_of_v" << endl;
        for (auto i = iters_of_v.begin(); i != iters_of_v.end(); ++i)
        {
            cout << **i << " ";
        }
        cout << endl;

        return 0;
    }
}
