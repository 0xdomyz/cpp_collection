// g++ urls.cpp split.cpp cross_ref.cpp -o cross_ref -std=c++20 && ./cross_ref < test_cross_ref.csv

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "split.h"
#include "urls.h"

using namespace std;

// find all the lines that refer to each word in the input
map<string, vector<int>>
xref(istream &in,
     vector<string> find_words(const string &) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;
    // read the next line
    while (getline(in, line))
    {

        ++line_number;
        // break the input line into words
        vector<string> words = find_words(line);
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}

void test_libs(void)
{
    const string s = "This is a test string";
    vector<string> v = split(s);
    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }

    const string s2 = "This is a https://adsf test str://ing";
    vector<string> v2 = find_urls(s2);
    for (vector<string>::const_iterator i = v2.begin(); i != v2.end(); ++i)
    {
        cout << *i << endl;
    }
}

int main(void)
{
    // call xref using split by default
    map<string, vector<int>> ret = xref(cin);
    // write the results
    for (map<string, vector<int>>::const_iterator it = ret.begin();
         it != ret.end(); ++it)
    {
        // write the word
        cout << it->first << " occurs on line(s): ";
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it; // write the first line number
        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }
        // write a new line to separate each word from the next
        cout << endl;
    }

    return 0;
}
