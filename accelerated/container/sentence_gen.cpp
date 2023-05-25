// g++ split.cpp sentence_gen.cpp -o sentence_gen && ./sentence_gen < grammar.csv

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"
#include <stdexcept>
#include <algorithm>
#include <list>

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

list<string>::size_type nrand(list<string>::size_type n)
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

void gen_aux(const Grammar &g, const string &word, list<string> &ret)
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

const Rule &gen_aux_one_round(const Grammar &g, const string &word)
{
    Grammar::const_iterator it = g.find(word);
    if (it == g.end())
        throw logic_error("empty rule");
    const Rule_collection &c = it->second;
    const Rule &r = c[nrand(c.size())];
    return r;
}

// list<string> gen_sentence(const Grammar &g)
template <class Bi>
Bi gen_sentence(const Grammar &g, Bi ret)
{
    // via iteration
    // list<string> ret;
    // gen_aux(g, "<sentence>", ret);
    // return ret;

    // no iteration
    // vector<string> ret;
    vector<string> stack;
    string word = "<sentence>";
    stack.push_back(word);

    while (stack.size() > 0)
    {
        word = stack.back();
        stack.pop_back();
        if (!bracketed(word))
        {
            // add to first of ret
            // ret.insert(ret.begin(), word);
            *ret++ = word;
        }
        else
        {
            const Rule &r = gen_aux_one_round(g, word);
            for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
                stack.push_back(*i);
        }
    }

    // return list<string>(ret.begin(), ret.end());
    return ret;
}

ostream &operator<<(ostream &os, const list<string> &v)
{
    if (v.size() > 0)
    {
        list<string>::const_iterator it = v.begin();
        os << *it;
        ++it;
        while (it != v.end())
        {
            os << " " << *it;
            ++it;
        }
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<string> &v)
{
    if (v.size() > 0)
    {
        vector<string>::const_iterator it = v.begin();
        os << *it;
        ++it;
        while (it != v.end())
        {
            os << " " << *it;
            ++it;
        }
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
        // list<string> sentence = gen_sentence(grammar);

        // vector<string> sentence;
        // gen_sentence(grammar, back_inserter(sentence));
        // reverse(sentence.begin(), sentence.end());

        list<string> sentence;
        gen_sentence(grammar, back_inserter(sentence));
        reverse(sentence.begin(), sentence.end());

        cout << sentence << endl;
        // cout << sentence.end() << endl;
    }

    return 0;
}
