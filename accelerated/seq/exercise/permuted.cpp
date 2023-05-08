// g++ split.cpp permuted.cpp -o permuted && cat permuted_test.csv | ./permuted

#include <iostream>
#include <vector>
#include <string>
#include "split.h"
#include <algorithm>
#include <cctype>

using namespace std;

void print_vector(vector<string> v)
{
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
}

// combine vector of strings into one string
string combine(vector<string> v)
{
    string s;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        s += *i;
        if (i != v.end() - 1)
        {
            s += " ";
        }
    }
    return s;
}

int main(void)
{

    // read lines
    string s;
    vector<string> v;
    vector<vector<string>> lines;
    while (getline(cin, s))
    {
        v = split(s);

        cout << "original: ";
        print_vector(v);
        cout << endl;

        lines.push_back(v);
    }

    // rotate vectors
    vector<pair<vector<string>, int>> rotations;

    // for each element, create copy of v, rotate it
    for (auto l = lines.begin(); l != lines.end(); ++l)
    {

        auto v = *l;

        for (auto i = 0; i != v.size(); ++i)
        {
            vector<string> v_copy = v;
            rotate(v_copy.begin(), v_copy.begin() + i, v_copy.end());

            // stor into rotations
            rotations.push_back(make_pair(v_copy, i));
        }
    }

    // sort rotations
    auto func = [](pair<vector<string>, int> a, pair<vector<string>, int> b)
    {
        auto a_first_word = *a.first.begin();
        auto b_first_word = *b.first.begin();
        return toupper(a_first_word[0]) < toupper(b_first_word[0]);
    };
    sort(rotations.begin(), rotations.end(), func);

    // find maxlength of characters before last word, in lines
    auto max_length = 0;
    for (auto l = lines.begin(); l != lines.end(); l++)
    {
        auto vec = *l;
        auto last_word = *(vec.end() - 1);
        auto total_length = 0;
        for (auto i = vec.begin(); i != vec.end() - 1; ++i)
        {
            total_length += (i->size() + 1);
        }
        total_length -= 1; // remove last space
        if (total_length > max_length)
        {
            max_length = total_length;
        }
    }
    cout << "max length: " << max_length << endl;

    // unrotate
    for (auto i = rotations.begin(); i != rotations.end(); ++i)
    {
        auto vec = i->first;
        auto rotate_amount = i->second;

        rotate(vec.begin(), vec.begin() + (vec.size() - rotate_amount), vec.end());

        // copy it back to rotations
        i->first = vec;
    }

    // print rotations
    // for (auto i = rotations.begin(); i != rotations.end(); ++i)
    // {
    //     cout << "rotated " << i->second << ": ";
    //     print_vector(i->first);
    //     cout << endl;
    // }

    // split by rotation amount to left and right
    vector<pair<vector<string>, vector<string>>> left_right;
    for (auto i = rotations.begin(); i != rotations.end(); ++i)
    {
        auto vec = i->first;
        auto rotate_amount = i->second;

        vector<string> left(vec.begin(), vec.begin() + rotate_amount);
        vector<string> right(vec.begin() + rotate_amount, vec.end());

        left_right.push_back(make_pair(left, right));
    }

    // print left and right
    for (auto i = left_right.begin(); i != left_right.end(); ++i)
    {
        string left = combine(i->first);
        left += string(max_length - left.size(), ' ');
        cout << left;

        cout << "\t";

        string right = combine(i->second);
        cout << right;

        cout << endl;
    }

    return 0;
}
