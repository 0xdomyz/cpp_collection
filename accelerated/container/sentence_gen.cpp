// g++ split.cpp sentence_gen.cpp -o sentence_gen && ./sentence_gen < grammar.csv

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// read a grammar from a given input stream
Grammar read_grammar(istream &in)
{
    Grammar ret;
    string line;
    // read the input
    while (getline(in, line))
    {
        // split the input into words
        vector<string> entry = split(line);
        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

ostream &operator<<(ostream &os, const Grammar &grammar)
{
    for (auto it = grammar.begin(); it != grammar.end(); ++it)
    // each is a pair<string, Rule_collection>
    {
        cout << it->first << endl;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        // each is a Rule
        {
            cout << "\t rule:";
            for (auto it3 = it2->begin(); it3 != it2->end(); ++it3)
            // each is a string
            {
                cout << *it3 << " ";
            }
            cout << endl;
        }
    }
    return os;
}

int main(void)
{
    Grammar grammar = read_grammar(cin);

    cout << "grammar:" << endl;
    cout << grammar << endl;

    return 0;
}
