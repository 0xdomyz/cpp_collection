// Compile and run: g++ predicates.cpp -o predicates && ./predicates

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Greater_than
{
    int val;
    Greater_than(int v) : val{v} {}
    bool operator()(const pair<string, int> &r) { return r.second > val; }
};

void f(map<string, int> &m)
{
    auto p = find_if(m.begin(), m.end(), Greater_than{42});
    if (p != m.end())
        cout << "Found " << p->first << " " << p->second << endl;
}

int main(void)
{

    map<string, int> m{{"a", 1}, {"b", 209}, {"c", 398}};

    f(m);

    int cxx = count_if(m.begin(), m.end(), [](const pair<string, int> &r)
                       { return r.second > 42; });
    cout << "cxx = " << cxx << endl;

    return 0;
}
