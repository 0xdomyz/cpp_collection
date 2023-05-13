// g++ split.cpp picture.cpp -o picture && cat test_picture.csv | ./picture

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "split.h"
#include "frame.h"
#include <algorithm>

using namespace std;

vector<string> vcat(const vector<string> &top,
                    const vector<string> &bottom)
{
    // copy the top picture
    vector<string> ret = top;
    // copy entire bottom picture

    // via iterator
    // for (vector<string>::const_iterator it = bottom.begin();
    //      it != bottom.end(); ++it)
    //     ret.push_back(*it);

    // via insert method
    // ret.insert(ret.end(), bottom.begin(), bottom.end());

    // via algo
    copy(bottom.begin(), bottom.end(), back_inserter(ret));

    return ret;
}

vector<string>
hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> ret;
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    // continue until we've seen all rows from both pictures
    for (auto i = left.begin(), j = right.begin();
         i != left.end() || j != right.end();)
    {
        // construct new string to hold characters from both pictures
        string s;
        // copy a row from the left-hand side, if there is one
        if (i != left.end())
            s = *i++; // ++ has higher precedence than *
        // pad to full width
        s += string(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += *j++;
        // add s to the picture we're creating
        ret.push_back(s);
    }

    // using indices
    // indices to look at elements from left and right respectively
    // vector<string>::size_type i = 0, j = 0;
    // while (i != left.size() || j != right.size())
    // {
    //     // construct new string to hold characters from both pictures
    //     string s;
    //     // copy a row from the left-hand side, if there is one
    //     if (i != left.size())
    //         s = left[i++];
    //     // pad to full width
    //     s += string(width1 - s.size(), ' ');
    //     // copy a row from the right-hand side, if there is one
    //     if (j != right.size())
    //         s += right[j++];
    //     // add s to the picture we're creating
    //     ret.push_back(s);
    // }

    return ret;
}

vector<string> center(const vector<string> &pic)
{
    vector<string> ret;
    auto interior_len = pic.begin()->size() - 4;
    // cout << "interior_len: " << interior_len << endl;

    // copy first row
    ret.push_back(*pic.begin());

    // build interior rows
    for (auto it = pic.begin() + 1; it != pic.end() - 1; ++it)
    {
        // extract interior string, remove excessive spaces at the end
        string s = it->substr(2, interior_len);
        for (auto rit = s.rbegin(); rit != s.rend(); ++rit)
        {
            if (*rit != ' ')
            {
                s = s.substr(0, s.size() - (rit - s.rbegin()));
                break;
            }
        }

        // position to the middle, via difference of interior_len and string length
        // divide by 2 to get the number of spaces to add to the left and right
        auto pos = (interior_len - s.size()) / 2;
        auto pos2 = (interior_len - s.size()) % 2;
        string payload = string(pos, ' ') + s + string(pos + pos2, ' ');
        ret.push_back("* " + payload + " *");
    }

    // copy last row
    ret.push_back(*pic.rbegin());

    return ret;
}

int main(void)
{
    // read and split each line of input
    string s;
    vector<string> v;
    while (getline(cin, s))
        v.push_back(s);

    vector<string> pic = frame(v);

    // write each line of output
    cout << "pic:" << endl;
    cout << pic << endl;

    // read a csv file using fstream
    ifstream infile("test_picture2.csv");
    string line;
    vector<string> v2;
    while (getline(infile, line))
        v2.push_back(line);

    vector<string> pic2 = frame(v2);
    cout << "pic2:" << endl;
    cout << pic2 << endl;

    // concatenate two pictures
    vector<string> pic3 = vcat(pic, pic2);
    cout << "pic3:" << endl;
    cout << pic3 << endl;

    // concatenate two pictures
    vector<string> pic4 = hcat(pic, pic2);
    cout << "pic4:" << endl;
    cout << pic4 << endl;

    // hcat a unframed picture and a framed picture
    vector<string> pic5 = hcat(v, pic2);
    // vector<string> pic5 = hcat(pic, v2);
    cout << "pic5:" << endl;
    cout << pic5 << endl;

    // centralise a picture's contents
    vector<string> pic6 = center(pic);
    cout << "pic6:" << endl;
    cout << pic6 << endl;

    return 0;
}
