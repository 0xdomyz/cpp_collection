#ifndef GUARD_VEC_H
#define GUARD_VEC_H

template <class T>
class Vec
{
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_type n, const T &val = T()) { create(n, val); }
    Vec(const Vec &v) { create(v.begin(), v.end()); }

    size_type size() const
    {
        return limit - data;
    }

    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; }
    const_iterator end() const { return limit; }

private:
    iterator data;
    iterator limit;
};

#endif // GUARD_VEC_H
