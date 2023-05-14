// g++ counting_word.cpp -o counting_word -std=c++17 && echo "a a b 1 12 1  " | ./counting_word

#include <iostream>
#include <string>
#include <map>
#include "type_name.h"

using namespace std;

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter
    // read the input, keeping track of each word and how often we see it
    while (cin >> s)
        ++counters[s];
    // write the words and associated counts
    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    // cout type of a particular value
    auto x = counters["a"];
    cout << "type of counters[\"a\"] is " << type_name<decltype(x)>() << endl;

    // mutate x
    x += 100;

    // check if x is a reference by comparing the value of counters["a"]
    cout << "counters[\"a\"] after mutating x is " << counters["a"] << endl;
    cout << "x's value is " << x << endl;
    cout << "x is " << (x == counters["a"] ? "" : "not ") << "a reference" << endl;

    return 0;
}
