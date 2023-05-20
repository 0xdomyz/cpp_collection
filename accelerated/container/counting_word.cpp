// g++ counting_word.cpp -o counting_word -std=c++17 && echo "a a b 1 12 1  " | ./counting_word

#include <iostream>
#include <string>
#include <map>
#include "type_name.h"
#include <vector>
#include <algorithm>

using namespace std;

void test_types(void)
{
    map<string, int> counters;
    counters["a"] = 1;
    // cout type of a particular value
    auto x = counters["a"];
    cout << "type of counters[\"a\"] is " << type_name<decltype(x)>() << endl;

    // mutate x
    x += 100;

    // check if x is a reference by comparing the value of counters["a"]
    cout << "counters[\"a\"] after mutating x is " << counters["a"] << endl;
    cout << "x's value is " << x << endl;
    cout << "x is " << (x == counters["a"] ? "" : "not ") << "a reference" << endl;
}

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter
    // read the input, keeping track of each word and how often we see it
    while (cin >> s)
        ++counters[s];

    // put pairs into a vector, sort by count
    vector<pair<string, int>> pairs;
    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it)
    {
        pairs.push_back(*it);
    }

    auto cmp = [](const pair<string, int> &a, const pair<string, int> &b)
    {
        return a.second < b.second;
    };

    sort(pairs.begin(), pairs.end(), cmp);

    // write the words and associated counts
    for (auto it = pairs.begin();
         it != pairs.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}
