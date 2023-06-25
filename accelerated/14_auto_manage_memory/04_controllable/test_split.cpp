// g++ test_split.cpp -o test_split && ./test_split

#include "split.h"
#include <iostream>
#include "Str.h"
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<Str> &v)
{
    for (vector<Str>::size_type i = 0; i != v.size(); ++i)
    {
        os << v[i] << endl;
    }
    return os;
}

int main()
{
    Str v = "Hello World !";
    vector<Str> vec;

    split(v, back_inserter(vec));

    cout << vec << endl;
}
