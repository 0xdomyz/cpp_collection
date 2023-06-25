#ifndef GUARD_frame
#define GUARD_frame

#include <iostream>
#include "Str.h"
#include <vector>

// find the length of the longest string in v
Str::size_type width(const std::vector<Str> &v)
{
    Str::size_type maxlen = 0;
    for (auto i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}

// write a vector<string> to an output stream: cout << v << endl;
std::ostream &operator<<(std::ostream &os, const std::vector<Str> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        os << *it << std::endl;
    return os;
}

std::vector<Str> frame(const std::vector<Str> &v)
{
    std::vector<Str> ret;
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        ret.push_back("* " + *i +
                      Str(maxlen - (*i).size(), ' ') + " *");
    }

    ret.push_back(border);

    return ret;
}

#endif