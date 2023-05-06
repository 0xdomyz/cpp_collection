
#include "read_words.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// read in words from an input stream, storing them in a vector
// stop when we hit the word "end" or the end of the input
istream &read_words(istream &in, vector<string> &words)
{
    if (in)
    {
        words.clear();

        string word;
        while (in >> word)
        {
            if (word == "end")
            {
                in.clear();
                break;
            }

            words.push_back(word);
        }

        if (in.eof() && words.size() > 0)
        {
            in.clear();
        }
    }
    return in;
}

void print_words(vector<string> &words)
{
    for (vector<string>::size_type i = 0; i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
}
