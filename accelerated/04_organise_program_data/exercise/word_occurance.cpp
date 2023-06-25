// g++ word_occurance.cpp read_words.cpp -o word_occurance && echo "aaa bbb 986 ccc 986 5 45wtyg s  s " | ./word_occurance

#include <iostream>
#include <string>
#include <vector>
#include "read_words.h"
#include <map>

using namespace std;

int main(void)
{
    vector<string> words;
    map<string, int> word_occurance;

    read_words(cin, words);
    print_words(words);

    cout << "number of words: " << words.size() << endl;

    for (auto i = 0; i < words.size(); i++)
    {
        word_occurance[words[i]]++;
    }

    for (auto i = word_occurance.begin(); i != word_occurance.end(); i++)
    {
        cout << i->first << ": " << i->second << endl;
    }

    return 0;
}
