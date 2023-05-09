// g++ asc_desc.cpp -o asc_desc && ./asc_desc test_dict.csv

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <fstream>

using namespace std;

bool has_ascenders(const string &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == 'b' || *it == 'd' || *it == 'f' || *it == 'h' || *it == 'k' || *it == 'l' || *it == 't')
        {
            return true;
        }
    }
    return false;
}

bool has_descenders(const string &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == 'g' || *it == 'j' || *it == 'p' || *it == 'q' || *it == 'y')
        {
            return true;
        }
    }
    return false;
}

string longest_word(const list<string> &lst)
{
    string longest = "";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        if (it->size() > longest.size())
        {
            longest = *it;
        }
    }
    return longest;
}

int main(int argc, char *argv[])
{
    // read in dict, store into list, name of file from cmd
    string filename = argv[1];
    ifstream infile(filename);
    string word;
    list<string> words;
    while (infile >> word)
    {
        words.push_back(word);
    }

    // loop thru, only leave words that is neither asc nor desc
    auto it = words.begin();
    while (it != words.end())
    {
        if (has_ascenders(*it) || has_descenders(*it))
        {
            it = words.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // print out the number of words left
    cout << "Number of words left: " << words.size() << endl;

    // find longest word
    cout << "Longest word: " << longest_word(words) << endl;
}