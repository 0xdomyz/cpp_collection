#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H

#include <algorithm>
#include <string>
#include <cctype>

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

template <class Out> // changed
void split(const std::string &str, Out os)
{ // changed
    typedef std::string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end())
    {
        // ignore leading blanks
        i = std::find_if(i, str.end(), not_space);
        // find end of next word
        iter j = std::find_if(i, str.end(), space);
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = std::string(i, j); // changed
        i = j;
    }
}

template <class container>
container split(const std::string &str)
{
    typedef std::string::const_iterator iter;
    iter i = str.begin();
    container cont;
    while (i != str.end())
    {
        // ignore leading blanks
        i = std::find_if(i, str.end(), not_space);
        // find end of next word
        iter j = std::find_if(i, str.end(), space);
        // copy the characters in [i, j)
        if (i != str.end())
            cont.push_back(std::string(i, j));
        i = j;
    }
    return cont;
}

#endif // GUARD_SPLIT_H
