// g++ split.cpp sentence_gen.cpp -o sentence_gen && ./sentence_gen < grammar.csv

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"
#include <stdexcept>
#include <algorithm>

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

bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

vector<string>::size_type nrand(vector<string>::size_type n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    // randome number between 0 and n-1, with equal probability
    const int bucket_size = RAND_MAX / n;
    int r;

    do
    {
        r = rand() / bucket_size;
    } while (r >= n);

    return r;
}

void gen_aux(const Grammar &g, const string &word, vector<string> &ret)
{
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        // fetch the set of possible rules
        const Rule_collection &c = it->second;
        // from which we select one at random
        const Rule &r = c[nrand(c.size())];
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar &g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

ostream &operator<<(ostream &os, const vector<string> &v)
{
    if (v.size() > 0)
    {
        os << v[0];
        for (vector<string>::size_type i = 1; i < v.size(); ++i)
            os << " " << v[i];
    }
    return os;
}

int main(void)
{
    srand(time(NULL));

    Grammar grammar = read_grammar(cin);

    cout << "grammar:" << endl;
    cout << grammar << endl;

    // gen 10 sentences
    for (int i = 0; i < 10; ++i)
    {
        vector<string> sentence = gen_sentence(grammar);
        cout << sentence << endl;
    }

    return 0;
}
