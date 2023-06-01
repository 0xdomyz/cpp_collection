#include "vec.h"
#include <cstring>

class Str
{
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

    friend std::istream &operator>>(std::istream &, Str &);
    friend std::ostream &operator<<(std::ostream &, const Str &);

private:
    Vec<char> data;
};

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (auto i = s.data.begin(); i != s.data.end(); ++i)
        os << *i;
    return os;
}