#ifndef GUARD_SPLIT_H
#define GUARD_SPLIT_H

#include <algorithm>
#include "str.h"
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
void split(const Str &str, Out os)
{ // changed
    typedef Str::const_iterator iter;
    iter i = str.begin();
    while (i != str.end())
    {
        // ignore leading blanks
        i = std::find_if(i, str.end(), not_space);
        // find end of next word
        iter j = std::find_if(i, str.end(), space);
        // copy the characters in [i, j)
        if (i != str.end())
            *os++ = Str(i, j); // changed
        i = j;
    }
}

template <class container>
container split(const Str &str)
{
    typedef Str::const_iterator iter;
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
            cont.push_back(Str(i, j));
        i = j;
    }
    return cont;
}

#endif // GUARD_SPLIT_H
