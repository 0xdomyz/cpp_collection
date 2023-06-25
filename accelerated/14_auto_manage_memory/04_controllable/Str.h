#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <cstring>
#include <iostream>
#include "vec.h"
#include "Ptr.h"

template <>
Vec<char> *clone(const Vec<char> *vp)
{
    // std::cout << "Vec<char> *clone(const Vec<char> *vp)" << std::endl;
    return new Vec<char>(*vp);
}

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);

public:
    typedef Vec<char>::size_type size_type;
    typedef Vec<char>::iterator iterator;
    typedef Vec<char>::const_iterator const_iterator;

    Str &operator+=(const Str &s)
    {
        data.make_unique();
        std::copy(s.data->begin(), s.data->end(),
                  std::back_inserter(*data));
        return *this;
    }

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

    iterator begin()
    {
        data.make_unique();
        return data->begin();
    }
    const_iterator begin() const { return data->begin(); }
    iterator end()
    {
        data.make_unique();
        return data->end();
    }
    const_iterator end() const { return data->end(); }

    Str substr(size_type i, size_type length) const
    {
        Str ret;
        std::copy(data->begin() + i, data->begin() + i + length,
                  std::back_inserter(*ret.data));
        return ret;
    }

    std::istream &getline(std::istream &is)
    {
        data.make_unique();
        data->clear();
        char c;
        while (is.get(c) && c != '\n')
            data->push_back(c);
        return is;
    }

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
