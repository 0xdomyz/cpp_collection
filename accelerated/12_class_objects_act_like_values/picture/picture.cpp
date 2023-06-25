// g++ picture.cpp str.cpp -o picture && cat test_picture.csv | ./picture

#include <iostream>
#include "str.h"
#include <vector>
#include <fstream>
#include "frame.h"
#include <algorithm>

using namespace std;

vector<Str> vcat(const vector<Str> &top,
                 const vector<Str> &bottom)
{
    // copy the top picture
    vector<Str> ret = top;
    // copy entire bottom picture

    // via algo
    copy(bottom.begin(), bottom.end(), back_inserter(ret));

    return ret;
}

vector<Str>
hcat(const vector<Str> &left, const vector<Str> &right)
{
    vector<Str> ret;
    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;
    // continue until we've seen all rows from both pictures
    for (auto i = left.begin(), j = right.begin();
         i != left.end() || j != right.end();)
    {
        // construct new Str to hold characters from both pictures
        Str s;
        // copy a row from the left-hand side, if there is one
        if (i != left.end())
            s = *i++; // ++ has higher precedence than *
        // pad to full width
        s += Str(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += *j++;
        // add s to the picture we're creating
        ret.push_back(s);
    }

    return ret;
}

vector<Str> center(const vector<Str> &pic)
{
    vector<Str> ret;
    auto interior_len = pic.begin()->size() - 4;
    // cout << "interior_len: " << interior_len << endl;

    // copy first row
    ret.push_back(*pic.begin());

    // build interior rows
    for (auto it = pic.begin() + 1; it != pic.end() - 1; ++it)
    {
        // extract interior Str, remove excessive spaces at the end
        Str s = it->substr(2, interior_len);
        for (auto it = s.end() - 1; it != s.begin(); --it)
        {
            if (*it != ' ')
            {
                s = s.substr(0, (it - s.begin() + 1));
                break;
            }
        }

        // position to the middle, via difference of interior_len and Str length
        // divide by 2 to get the number of spaces to add to the left and right
        auto pos = (interior_len - s.size()) / 2;
        auto pos2 = (interior_len - s.size()) % 2;
        Str payload = Str(pos, ' ') + s + Str(pos + pos2, ' ');
        ret.push_back("* " + payload + " *");
    }

    // copy last row
    ret.push_back(*pic.rbegin());

    return ret;
}

int main(void)
{
    // read and split each line of input
    Str s;
    vector<Str> v;
    while (s.getline(cin))
        v.push_back(s);

    vector<Str> pic = frame(v);

    // write each line of output
    cout << "pic:" << endl;
    cout << pic << endl;

    // read a csv file using fstream
    ifstream infile("test_picture2.csv");
    Str line;
    vector<Str> v2;
    while (line.getline(infile))
        v2.push_back(line);

    vector<Str> pic2 = frame(v2);
    cout << "pic2:" << endl;
    cout << pic2 << endl;

    // concatenate two pictures
    vector<Str> pic3 = vcat(pic, pic2);
    cout << "pic3:" << endl;
    cout << pic3 << endl;

    // concatenate two pictures
    vector<Str> pic4 = hcat(pic, pic2);
    cout << "pic4:" << endl;
    cout << pic4 << endl;

    // hcat a unframed picture and a framed picture
    vector<Str> pic5 = hcat(v, pic2);
    // vector<Str> pic5 = hcat(pic, v2);
    cout << "pic5:" << endl;
    cout << pic5 << endl;

    // centralise a picture's contents
    vector<Str> pic6 = center(pic);
    cout << "pic6:" << endl;
    cout << pic6 << endl;

    return 0;
}
