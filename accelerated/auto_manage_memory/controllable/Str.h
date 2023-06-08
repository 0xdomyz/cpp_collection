#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <cstring>
#include <iostream>
#include "vec.h"
#include "Ptr.h"

template <>
Vec<char> *clone(const Vec<char> *vp)
{
    return new Vec<char>(*vp);
}

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);

public:
    Str &operator+=(const Str &s)
    {
        data.make_unique();
        std::copy(s.data->begin(), s.data->end(),
                  std::back_inserter(*data));
        return *this;
    }
    // interface as before
    typedef Vec<char>::size_type size_type;
    // reimplement constructors to create Ptrs
    Str() : data(new Vec<char>) {}
    Str(const char *cp) : data(new Vec<char>)
    {
        std::copy(cp, cp + std::strlen(cp),
                  std::back_inserter(*data));
    }
    Str(size_type n, char c) : data(new Vec<char>(n, c)) {}
    template <class In>
    Str(In i, In j) : data(new Vec<char>)
    {
        std::copy(i, j, std::back_inserter(*data));
    }
    // call make_unique as necessary
    char &operator[](size_type i)
    {
        data.make_unique();
        return (*data)[i];
    }
    const char &operator[](size_type i) const { return (*data)[i]; }
    size_type size() const { return data->size(); }

private:
    // store a Ptr to a vector
    Ptr<Vec<char>> data;
};

// as implemented in §12.3.2/216 and §12.3.3/219
std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
};

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
};

#endif
