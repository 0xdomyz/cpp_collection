#ifndef GUARD_frame
#define GUARD_frame

#include <iostream>
#include <string>
#include <vector>

// find the length of the longest string in v
std::string::size_type width(const std::vector<std::string> &v)
{
    std::string::size_type maxlen = 0;
    for (auto i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}

// write a vector<string> to an output stream: cout << v << endl;
std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        os << *it << std::endl;
    return os;
}

std::vector<std::string> frame(const std::vector<std::string> &v)
{
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        ret.push_back("* " + *i +
                      std::string(maxlen - (*i).size(), ' ') + " *");
    }

    // using indices
    // for (auto i = 0; i != v.size(); ++i)
    // {
    //     ret.push_back("* " + v[i] +
    //                   std::string(maxlen - v[i].size(), ' ') + " *");
    // }
    // write the bottom border
    ret.push_back(border);

    return ret;
}

#endif