
#include <iostream>
#include <cstring>
#include <algorithm>
#include "str.h"
#include <iterator>

using namespace std;

void Str::push_back(const char &c)
{

    char *new_data_ = new char[len + 1];
    std::copy(data_, data_ + len, new_data_);
    new_data_[len] = c;
    new_data_[len + 1] = '\0';
    delete[] data_;
    data_ = new_data_;
    ++len;
}

void Str::copy(char *p, size_type n) const
{
    std::copy(data_, data_ + n, p);
};

void Str::getline(std::istream &is)
{
    delete[] data_;
    data_ = new char[1];
    data_[0] = '\0';
    len = 0;
    char c;
    while (is.get(c) && c != '\n')
        push_back(c);
}

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    ostream_iterator<char> os_iter(os);
    copy(s.begin(), s.end(), os_iter);
    return os;
}

std::istream &operator>>(std::istream &is, Str &s)
{
    // obliterate existing value(s)
    delete[] s.data_;
    s.data_ = new char[1];
    s.data_[0] = '\0';
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
    char *new_data_ = new char[len + s.len + 1];
    std::copy(data_, data_ + len, new_data_);
    std::copy(s.data_, s.data_ + s.len, new_data_ + len);
    new_data_[len + s.len] = '\0';
    delete[] data_;
    data_ = new_data_;
    len += s.len;
    return *this;
}

Str &Str::operator+=(const char *s)
{
    char *new_data_ = new char[len + strlen(s) + 1];
    std::copy(data_, data_ + len, new_data_);
    std::copy(s, s + strlen(s), new_data_ + len);
    new_data_[len + strlen(s)] = '\0';
    delete[] data_;
    data_ = new_data_;
    len += strlen(s);
    return *this;
};

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str &s, const char *cs)
{
    Str r = s;
    r += cs;
    return r;
};

bool operator==(const Str &s, const Str &t)
{
    int res = strcmp(s.c_str(), t.c_str());
    return res == 0;
}

bool operator!=(const Str &s, const Str &t)
{
    return !(s == t);
};

bool operator<(const Str &s, const Str &t)
{
    int res = strcmp(s.c_str(), t.c_str());
    return res < 0;
};
bool operator>(const Str &s, const Str &t)
{
    return !(s <= t);
};
bool operator<=(const Str &s, const Str &t)
{
    return s < t || s == t;
};
bool operator>=(const Str &s, const Str &t)
{
    return !(s < t);
};
