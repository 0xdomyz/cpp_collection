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
    Str(size_type n, char c) : content(n, c) {}
    // create a Str from a null-terminated array of char
    Str(const char *cp)
    {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(content));
    }
    // create a Str from the range denoted by iterators b and e
    template <class In>
    Str(In b, In e)
    {
        std::copy(b, e, std::back_inserter(content));
    }

    size_type size() const { return content.size(); }

    char &operator[](size_type i) { return content[i]; }
    const char &operator[](size_type i) const
    {
        return content[i];
    }

    Str &operator+=(const Str &s)
    {
        std::copy(s.content.begin(), s.content.end(),
                  std::back_inserter(content));
        return *this;
    }

    const char *c_str();
    const char *data();

private:
    Vec<char> content;
};

Str operator+(const Str &, const Str &);

// implementations

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

const char *Str::c_str()
{
    static char *c_str_ = nullptr;

    delete[] c_str_;
    c_str_ = new char[content.size() + 1];
    std::copy(content.begin(), content.end(), c_str_);
    c_str_[content.size()] = '\0';
    return c_str_;
}

const char *Str::data()
{
    static char *c_str_2 = nullptr;

    delete[] c_str_2;
    c_str_2 = new char[content.size()];
    std::copy(content.begin(), content.end(), c_str_2);
    return c_str_2;
}

#endif