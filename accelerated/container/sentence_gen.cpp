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

int main(void)
{
    Grammar grammar = read_grammar(cin);
    for (Grammar::const_iterator it = grammar.begin(); it != grammar.end(); ++it)
    {
        cout << it->first << endl;
        for (Rule_collection::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            for (Rule::const_iterator it3 = it2->begin(); it3 != it2->end(); ++it3)
            {
                cout << *it3 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}