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
    typedef char *iterator;

    // constructors
    Str() : data_(new char[1]), len(0)
    {
        data_[0] = '\0';
    }

    Str(size_type n, char c) : data_(new char[n]), len(n)
    {
        std::fill(data_, data_ + len, c);
        data_[len] = '\0';
    }

    Str(const char *cp) : data_(new char[std::strlen(cp) + 1]), len(std::strlen(cp))
    {
        std::copy(cp, cp + std::strlen(cp), data_);
        data_[len] = '\0';
    }

    template <class In>
    Str(In b, In e) : data_(new char[e - b + 1]), len(e - b)
    {
        std::copy(b, e, data_);
        data_[len] = '\0';
    }

    // destructor
    ~Str()
    {
        delete[] data_;
        len = 0;
    }

    // copy constructor
    Str(const Str &s) : data_(new char[s.len + 1]), len(s.len)
    {
        std::copy(s.data_, s.data_ + s.len, data_);
        data_[len] = '\0';
    }

    // assignment operator
    Str &operator=(const Str &s)
    {
        if (&s != this)
        {
            delete[] data_;
            len = s.len;
            data_ = new char[len + 1];
            std::copy(s.data_, s.data_ + s.len, data_);
            data_[len] = '\0';
        }
        return *this;
    }

    size_type size() const { return len; }

    char &operator[](size_type i) { return data_[i]; }
    const char &operator[](size_type i) const
    {
        return data_[i];
    }

    operator void *() const
    {
        if (len == 0)
            return nullptr;
        return (void *)data_;
    }

    Str &operator+=(const Str &s);
    Str &operator+=(const char *s);
    void push_back(const char &c);

    const char *c_str() const { return data_; };
    const char *data() const { return data_; };
    void copy(char *p, size_type n) const;

    char *begin() { return data_; }
    const char *begin() const { return data_; }
    char *end() { return data_ + len; }
    const char *end() const { return data_ + len; }

    void getline(std::istream &is);

private:
    char *data_;
    size_type len;
};

std::ostream &operator<<(std::ostream &, const Str &);
std::istream &operator>>(std::istream &, Str &);

Str operator+(const Str &, const Str &);
Str operator+(const Str &, const char *);

bool operator==(const Str &, const Str &);
bool operator!=(const Str &, const Str &);
bool operator<(const Str &, const Str &);
bool operator>(const Str &, const Str &);
bool operator<=(const Str &, const Str &);
bool operator>=(const Str &, const Str &);

#endif