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

    // constructors
    Str() : _c_str(nullptr) {}
    Str(size_type n, char c) : content(n, c), _c_str(nullptr) {}
    Str(const char *cp) : _c_str(nullptr)
    {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(content));
    }
    template <class In>
    Str(In b, In e) : _c_str(nullptr)
    {
        std::copy(b, e, std::back_inserter(content));
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
    const char &operator[](size_type i) const
    {
        return content[i];
    }

    // concatenation operator
    Str &operator+=(const Str &s)
    {
        std::copy(s.content.begin(), s.content.end(),
                  std::back_inserter(content));
        return *this;
    }

    // member functions
    size_type size() const { return content.size(); }
    const char *c_str();
    const char *data() const;
    void copy(char *p, size_type n) const // copy into p
    {
        std::copy(content.begin(), content.begin() + n, p);
    }

private:
    Vec<char> content;
    char *_c_str;
};

Str operator+(const Str &, const Str &);
bool operator==(const Str &, const Str &);

#endif