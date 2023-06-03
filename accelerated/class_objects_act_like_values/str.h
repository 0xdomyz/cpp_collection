#ifndef GUARD_STR_H
#define GUARD_STR_H

#include "vec.h"
#include <cstring>

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);
    friend std::ostream &operator<<(std::ostream &, const Str &);

public:
    typedef Vec<char>::size_type size_type;

    // default constructor; create an empty Str
    Str() {}
    // create a Str containing n copies of c
    Str(size_type n, char c) : data(n, c) {}
    // create a Str from a null-terminated array of char
    Str(const char *cp)
    {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    // create a Str from the range denoted by iterators b and e
    template <class In>
    Str(In b, In e)
    {
        std::copy(b, e, std::back_inserter(data));
    }

    size_type size() const { return data.size(); }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const
    {
        return data[i];
    }

    Str &operator+=(const Str &s)
    {
        std::copy(s.data.begin(), s.data.end(),
                  std::back_inserter(data));
        return *this;
    }

    const char *c_str()
    {
        delete[] c_str_;
        c_str_ = new char[data.size() + 1];
        std::copy(data.begin(), data.end(), c_str_);
        c_str_[data.size()] = '\0';
        return c_str_;
    }

private:
    Vec<char> data;
    char *c_str_;
};

Str operator+(const Str &, const Str &);

// implementations

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (auto i = s.data.begin(); i != s.data.end(); ++i)
        os << *i;
    return os;
}

std::istream &operator>>(std::istream &is, Str &s)
{
    // obliterate existing value(s)
    s.data.clear();
    // read and discard leading whitespace
    char c;
    while (is.get(c) && std::isspace(c))
        ; // nothing to do, except testing the condition
          // if still something to read, do so until next whitespace character
    if (is)
    {
        do
            s.data.push_back(c);
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

#endif