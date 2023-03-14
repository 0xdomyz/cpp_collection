// Compile and run: g++ iterators.cpp -o iterators && ./iterators

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool has_c(const string &s, char c) // does s contain the character c?
{
    auto p = find(s.begin(), s.end(), c);
    if (p != s.end())
        return true;
    else
        return false;
}

bool has_c2(const string &s, char c) // does s contain the character c?
{
    return find(s.begin(), s.end(), c) != s.end();
}

vector<string::iterator> find_all(string &s, char c) // find all occurrences of c in s
{
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); ++p)
        if (*p == c)
            res.push_back(p);
    return res;
}

void test()
{
    string m{"Mary had a little lamb"};
    for (auto p : find_all(m, 'a'))
        if (*p != 'a')
            cerr << "a bug!\n";
}

template <typename C, typename V>
vector<typename C::iterator> find_all(C &c, V v) // find all occurrences of v in c
{
    vector<typename C::iterator> res;
    for (auto p = c.begin(); p != c.end(); ++p)
        if (*p == v)
            res.push_back(p);
    return res;
};

template <typename T>
using Iterator = typename T::iterator;

template <typename C, typename V>
vector<Iterator<C>> find_all2(C &c, V v) // find all occurrences of v in c
{
    vector<Iterator<C>> res;
    for (auto p = c.begin(); p != c.end(); ++p)
        if (*p == v)
            res.push_back(p);
    return res;
}

void test2()
{
    string m{"Mary had a little lamb"};
    for (auto p : find_all(m, 'a')) // p is a str ing::iterator
        if (*p != 'a')
            cerr << "string bug!\n";
    list<double> ld{1.1, 2.2, 3.3, 1.1};
    for (auto p : find_all(ld, 1.1))
        if (*p != 1.1)
            cerr << "list bug!\n";
    vector<string> vs{"red", "blue", "green", "green", "orange", "green"};
    for (auto p : find_all(vs, "green"))
        if (*p != "green")
            cerr << "vector bug!\n";
    for (auto p : find_all(vs, "green"))
        *p = "ver t";
}

int main()
{
    test();
    test2();
}