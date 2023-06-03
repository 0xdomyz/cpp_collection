#ifndef GUARD_STR_H
#define GUARD_STR_H

#include <iostream>
#include <cstring>

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);
    friend std::ostream &operator<<(std::ostream &, const Str &);

public:
    typedef size_t size_type;

    // constructors
    Str() : data(new char[0]), len(0) {}
    Str(size_type n, char c) : data(new char[n]), len(n)
    {
        std::fill(data, data + len, c);
    }
    Str(const char *cp) : data(new char[std::strlen(cp)]), len(std::strlen(cp))
    {
        std::copy(cp, cp + std::strlen(cp), data);
    }
    template <class In>
    Str(In b, In e) : data(new char[e - b]), len(e - b)
    {
        std::copy(b, e, data);
    }

    // destructor
    ~Str()
    {
        delete[] data;
        len = 0;
    }

    // copy constructor
    Str(const Str &s) : data(new char[s.len]), len(s.len)
    {
        std::copy(s.data, s.data + s.len, data);
    }

    // assignment operator
    Str &operator=(const Str &s)
    {
        if (&s != this)
        {
            delete[] data;
            len = s.len;
            data = new char[len];
            std::copy(s.data, s.data + s.len, data);
        }
        return *this;
    }

    size_type size() const { return len; }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const
    {
        return data[i];
    }

    Str &operator+=(const Str &s)
    {
        char *new_data = new char[len + s.len];
        std::copy(data, data + len, new_data);
        std::copy(s.data, s.data + s.len, new_data + len);
        delete[] data;
        data = new_data;
        len += s.len;
        return *this;
    }

    void push_back(const char &c)
    {
        if (len == 0)
        {
            data = new char[1];
            data[0] = c;
            len = 1;
        }
        else
        {
            char *new_data = new char[len + 1];
            std::copy(data, data + len, new_data);
            new_data[len] = c;
            delete[] data;
            data = new_data;
            ++len;
        }
    }

private:
    char *data;
    size_type len;
};

Str operator+(const Str &, const Str &);

// implementations

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (auto i = s.data; i != s.data + s.len; ++i)
        os << *i;
    return os;
}

std::istream &operator>>(std::istream &is, Str &s)
{
    // obliterate existing value(s)
    delete[] s.data;
    s.data = new char[0];
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

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}

#endif