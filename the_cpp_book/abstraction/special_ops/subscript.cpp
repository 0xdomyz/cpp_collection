// make a file of 3 words: echo "hello world hello" > words.txt
// complie and run: g++ -o subscript subscript.cpp && ./subscript < words.txt

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Assoc
{
    vector<pair<string, int>> vec; // vector of {name,value} pairs
    const int &operator[](const string &) const;
    int &operator[](const string &);
};

int &Assoc::operator[](const string &s)
// search for s; return a reference to its value if found;
// otherwise, make a new pair {s,0} and return a reference to its value
{
    for (auto &x : vec)
        if (x.first == s)
            return x.second; // return reference to value (§31.2.2)

    vec.push_back({s, 0});    // initial value: 0
    return vec.back().second; // return last element (§31.2.2)
}

int main() // count the occurrences of each word on input
{
    Assoc values;
    string buf;
    while (cin >> buf)
        ++values[buf];
    for (auto x : values.vec)
        cout << '{' << x.first << ',' << x.second << "}\n";
}