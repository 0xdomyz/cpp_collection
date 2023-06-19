#ifndef GUARD_STR_H
#define GUARD_STR_H

#include "vec.h"
#include <cstring>
#include <iostream>

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);
    friend std::ostream &operator<<(std::ostream &, const Str &);

public:
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    // constructors
    Str() : _c_str(nullptr) {}
    Str(size_type n, char c) : content(n, c), _c_str(nullptr) {}
    Str(const char *cp) : content(cp, cp + std::strlen(cp)), _c_str(nullptr)
    {
        // std::copy(cp, cp + std::strlen(cp), std::back_inserter(content));
    }
    template <class In>
    Str(In b, In e) : content(b, e), _c_str(nullptr)
    {
        // std::copy(b, e, std::back_inserter(content));
    }
    ~Str()
    {
        delete[] _c_str;
    }
    Str(const Str &s) : content(s.content), _c_str(nullptr) {}
    Str &operator=(const Str &s)
    {
        if (&s != this)
        {
            content = s.content;
        }
        return *this;
    }

    // index operator
    char &operator[](size_type i) { return content[i]; }
    const char &operator[](size_type i) const { return content[i]; }

    // concatenation operator
    Str &operator+=(const Str &s)
    {
        std::copy(s.content.begin(), s.content.end(),
                  std::back_inserter(content));
        return *this;
    }
    Str &operator+=(const char *s)
    {
        std::copy(s, s + std::strlen(s), std::back_inserter(content));
        return *this;
    };

    // member functions
    size_type size() const { return content.size(); }

    operator void *() const
    {
        return content.size() ? (void *)this : nullptr;
    }

    void push_back(char c) { content.push_back(c); }

    const char *c_str();
    const char *data() const;
    void copy(char *p, size_type n) const // copy into p
    {
        std::copy(content.begin(), content.begin() + n, p);
    }

    iterator begin() { return content.begin(); }
    const_iterator begin() const { return content.begin(); }
    iterator end() { return content.end(); }
    const_iterator end() const { return content.end(); }

    void getline(std::istream &is);

private:
    Vec<char> content;
    char *_c_str;
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