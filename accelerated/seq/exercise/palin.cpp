// g++ palin.cpp -o palin && ./palin test_dict.csv

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

// via iterators
// bool is_palindrome(const string &s)
// {
//     // iterate from start to end, compare to end to start
//     // can stop in the middle if the letters do match
//     // erase from vector if not a palindrome
//     auto start = s.begin();
//     auto end = s.end() - 1;
//     while (start < end)
//     {
//         if (*start != *end)
//         {
//             return false;
//         }
//         ++start;
//         --end;
//     }
//     return true;
// }

// via STL
bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

void print_first_and_last_5_elements(const list<string> &lst)
{
    cout << "First 5 elements: " << endl;
    {
        auto i = 0;
        for (auto it = lst.begin(); it != lst.end() && i < 5; ++it, ++i)
        {
            cout << *it << endl;
        }
    }

    // last 5 elements
    cout << "Last 5 elements: " << endl;
    {
        auto i = 0;
        for (auto it = lst.rbegin(); it != lst.rend() && i < 5; ++it, ++i)
        {
            cout << *it << endl;
        }
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    // read in a file with a list of words, one on each line, store in vector
    // file name from command line
    string filename = argv[1];
    ifstream infile(filename);
    string word;
    list<string> words;
    while (infile >> word)
    {
        words.push_back(word);
    }

    // print first 5 words in input and last 5 words
    print_first_and_last_5_elements(words);

    // for each word, iterate from start to end, compare to end to start
    // can stop in the middle if the letters do match
    // erase from vector if not a palindrome
    auto it = words.begin();
    while (it != words.end())
    {
        if (!is_palindrome(*it))
        {
            it = words.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // find longest palindrome in vector
    string longest;
    for (auto it = words.begin(); it != words.end(); ++it)
    {
        if (it->size() > longest.size())
        {
            longest = *it;
        }
    }

    // print out number of palindromes
    cout << "Number of palindromes: " << words.size() << endl;

    // print out first 5, and last 5 palindromes
    print_first_and_last_5_elements(words);

    // print out longest palindrome
    cout << "Longest palindrome: " << longest << endl;
}
