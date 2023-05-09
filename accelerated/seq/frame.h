#ifndef GUARD_frame
#define GUARD_frame

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// find the length of the longest string in v
std::string::size_type width(const std::vector<std::string> &v)
{
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> &v)
{
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');
    // write the top border
    ret.push_back(border);
    // write each interior row, bordered by an asterisk and a space
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] +
                      std::string(maxlen - v[i].size(), ' ') + " *");
    }
    // write the bottom border
    ret.push_back(border);
    return ret;
}

#endif