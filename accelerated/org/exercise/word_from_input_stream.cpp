// g++ word_from_input_stream.cpp -o word_from_input_stream && echo "aaa bbb end ccc end " | ./word_from_input_stream
// g++ word_from_input_stream.cpp -o word_from_input_stream && echo "aaa bbb 986 asdghh4 asdfj dasf s asdf" | ./word_from_input_stream

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

int main()
{
    vector<string> words;

    // basic
    // string word;
    // while (cin >> word)
    // {
    //     cout << "word: " << word << endl;
    // }
    // cout << cin.good() << endl;
    // cout << cin.eof() << endl;

    // basic with end word
    // string word;
    // while (cin >> word && word != "end")
    // {
    //     cout << "word: " << word << endl;
    // }
    // cout << word << endl;
    // cout << cin.good() << endl;
    // cout << cin.eof() << endl;

    while (read_words(cin, words))
    {
        print_words(words);
    }
    return 0;
}