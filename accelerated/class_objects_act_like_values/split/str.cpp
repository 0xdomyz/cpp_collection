#include "str.h"
#include <algorithm>

using namespace std;

const char *Str::c_str()
{
    // static char *_c_str = nullptr;
    delete[] _c_str;
    _c_str = new char[content.size() + 1];
    std::copy(content.begin(), content.end(), _c_str);
    _c_str[content.size()] = '\0';
    return _c_str;
}

const char *Str::data() const
{
    return content.begin();
}

void Str::getline(std::istream &is)
{
    char c;
    while (is.get(c) && c != '\n')
        content.push_back(c);
};

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (auto i = s.content.begin(); i != s.content.end(); ++i)
        os << *i;
    return os;
}

std::istream &operator>>(std::istream &is, Str &s)
{
    // obliterate existing value(s)
    s.content.clear();
    // read and discard leading whitespace
    char c;
    while (is.get(c) && std::isspace(c))
        ; // nothing to do, except testing the condition
          // if still something to read, do so until next whitespace character
    if (is)
    {
        do
            s.content.push_back(c);
        while (is.get(c) && !std::isspace(c));
        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str &s, const char *t)
{
    Str r = s;
    r += t;
    return r;
}

bool operator==(const Str &lhs, const Str &rhs)
{
    Str l = lhs;
    Str r = rhs;
    int res = strcmp(l.c_str(), r.c_str());
    return res == 0;
}

bool operator!=(const Str &lhs, const Str &rhs)
{
    return !(lhs == rhs);
};
bool operator<(const Str &lhs, const Str &rhs)
{
    Str l = lhs;
    Str r = rhs;
    int res = strcmp(l.c_str(), r.c_str());
    return res < 0;
};
bool operator>(const Str &lhs, const Str &rhs)
{
    Str l = lhs;
    Str r = rhs;
    int res = strcmp(l.c_str(), r.c_str());
    return res > 0;
};
bool operator<=(const Str &lhs, const Str &rhs)
{
    return !(lhs > rhs);
};
bool operator>=(const Str &lhs, const Str &rhs)
{
    return !(lhs < rhs);
};
