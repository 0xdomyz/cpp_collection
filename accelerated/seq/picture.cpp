// g++ split.cpp picture.cpp -o picture && cat test_picture.csv | ./picture

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "split.h"

using namespace std;

// find the length of the longest string in v
string::size_type width(const vector<string> &v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> frame(const vector<string> &v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] +
                      string(maxlen - v[i].size(), ' ') + " *");
    }
    // write the bottom border
    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string> &top,
                    const vector<string> &bottom)
{
    // copy the top picture
    vector<string> ret = top;
    // copy entire bottom picture
    // for (vector<string>::const_iterator it = bottom.begin();
    //      it != bottom.end(); ++it)
    //     ret.push_back(*it);
    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

vector<string>
hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> ret;
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;
    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size())
    {
        // construct new string to hold characters from both pictures
        string s;
        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        // pad to full width
        s += string(width1 - s.size(), ' ');
        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
        // add s to the picture we're creating
        ret.push_back(s);
    }
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

// write a vector<string> to an output stream: cout << v << endl;
ostream &operator<<(ostream &os, const vector<string> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        os << *it << endl;
    return os;
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
