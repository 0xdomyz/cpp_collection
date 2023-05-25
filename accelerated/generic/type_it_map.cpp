// g++ type_it_map.cpp -o type_it_map && ./type_it_map

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const map<int, string> &m)
{
    for (map<int, string>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        os << it->first << " " << it->second << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<pair<int, string>> &v)
{
    for (vector<pair<int, string>>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        os << it->first << " " << it->second << endl;
    }
    return os;
}

int main()
{
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";

    {

        vector<pair<int, string>> x;

        copy(m.begin(), m.end(), back_inserter(x));

        cout << x << endl;
    }

    {
        auto it = back_inserter(m);

        // *it = make_pair(3, "three");

        // map<int, string> x;
        // x[3] = "three";

        // vector<pair<int, string>> x;
        // x.push_back(make_pair(3, "three"));

        // copy(x.begin(), x.end(), back_inserter(m));
        // cout << m << endl;
    }
}
