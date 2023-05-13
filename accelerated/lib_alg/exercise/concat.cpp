// g++ concat.cpp -o concat && ./concat

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    // vector string of words
    vector<string> words;
    words.push_back("Hello");
    words.push_back("World");
    words.push_back("!");

    // accumulate all words in a single string, separated by spaces in between words
    string all_words = accumulate(words.begin(), words.end(), string(""));
    cout << all_words << endl;

    // use a space as a separator
    auto func = [](string a, string b)
    { return a + " " + b; };
    string all_words2 = accumulate(words.begin(), words.end(), string(""), func);
    // remove the first space
    all_words2.erase(all_words2.begin());
    cout << all_words2 << endl;
}