
#include <iostream>
#include <cstring>
#include <algorithm>
#include "str_no_vec.h"

using namespace std;

void Str::push_back(const char &c)
{
    if (len == 0)
    {
        data_ = new char[1];
        data_[0] = c;
        len = 1;
    }
    else
    {
        char *new_data_ = new char[len + 1];
        std::copy(data_, data_ + len, new_data_);
        new_data_[len] = c;
        delete[] data_;
        data_ = new_data_;
        ++len;
    }
}

void Str::copy(char *p, size_type n) const
{
    std::copy(data_, data_ + n, p);
};

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (auto i = s.data_; i != s.data_ + s.len; ++i)
        os << *i;
    return os;
}

std::istream &operator>>(std::istream &is, Str &s)
{
    // obliterate existing value(s)
    delete[] s.data_;
    s.data_ = new char[0];
    s.len = 0;
    // read and discard leading whitespace
    char c;
    while (is.get(c) && std::isspace(c))
        ; // nothing to do, except testing the condition
          // if still something to read, do so until next whitespace character
    if (is)
    {
        do
            s.push_back(c);
        while (is.get(c) && !std::isspace(c));
        // if we read whitespace, then put it back on the stream
        if (is)
            is.unget();
    }
    return is;
}

Str &Str::operator+=(const Str &s)
{
    char *new_data_ = new char[len + s.len];
    std::copy(data_, data_ + len, new_data_);
    std::copy(s.data_, s.data_ + s.len, new_data_ + len);
    delete[] data_;
    data_ = new_data_;
    len += s.len;
    return *this;
}

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}

bool operator==(const Str &s, const Str &t)
{
    int res = strcmp(s.c_str(), t.c_str());
    return res == 0;
}
