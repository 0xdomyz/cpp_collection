// g++ dist_word.cpp -o dist_word && ./dist_word

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    map<string, int> counters;
    string s;

    // read the input, keeping track of each word and how often we see it
    cout << "Enter words, enter 'quit' to quit" << endl;
    while (cin >> s && s != "quit")
    {
        ++counters[s];
    }

    // rank
    vector<pair<string, int>> vec_counters(counters.begin(), counters.end());
    auto func = [](const pair<string, int> &a, const pair<string, int> &b)
    { return a.second > b.second; };
    sort(vec_counters.begin(), vec_counters.end(), func);

    // write the words and associated counts
    for (auto it = vec_counters.begin(); it != vec_counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}