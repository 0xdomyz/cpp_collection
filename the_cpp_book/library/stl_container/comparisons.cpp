// g++ comparisons.cpp -o comparisons && ./comparisons

// template <typename Ran>
// void sort(Ran first, Ran last); // use < for comparison
// template <typename Ran, typename Cmp>
// void sort(Ran first, Ran last, Cmp cmp); // use cmp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

// header for strcmp()
#include <cstring>

using namespace std;

class Nocase
{ // case-insensitive str ing compare
public:
    bool operator()(const string &, const string &) const;
};
bool Nocase::operator()(const string &x, const string &y) const
// return tr ue if x is lexicographically less than y, not taking case into account
{
    auto p = x.begin();
    auto q = y.begin();
    while (p != x.end() && q != y.end() && toupper(*p) == toupper(*q))
    {
        ++p;
        ++q;
    }
    if (p == x.end())
        return q != y.end();
    if (q == y.end())
        return false;
    return toupper(*p) < toupper(*q);
}

struct Cstring_less
{
    bool operator()(const char *p, const char *q) const { return strcmp(p, q) < 0; }
};

void print_vector(vector<string> &v)
{
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

int main(void)
{
    vector<string> fruit = {"apple", "Orange", "Banana", "lemon", "grape"};
    print_vector(fruit);

    sort(fruit.begin(), fruit.end(), Nocase());
    cout << "case-insensitive sort: \n";
    print_vector(fruit);

    sort(fruit.begin(), fruit.end());
    cout << "case-sensitive sort: \n";
    print_vector(fruit);

    map<const char *, int> m;
    m["apple"] = 1;
    m["Orange"] = 2;
    m["banana"] = 3;

    cout << "map: \n";
    for (auto &x : m)
        cout << x.first << " " << x.second << endl;

    map<const char *, int, Cstring_less> m2; // map that uses strcmp() to compare const char* keys
    m2["apple"] = 1;
    m2["Orange"] = 2;
    m2["banana"] = 3;

    cout << "map2: \n";
    for (auto &x : m2)
        cout << x.first << " " << x.second << endl;
}
