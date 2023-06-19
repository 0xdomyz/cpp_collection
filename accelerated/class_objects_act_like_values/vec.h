#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include <memory>
#include <iostream>

template <class T>
class Vec
{
public:
    // interface types
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // constructors
    Vec() { create(); }
    explicit Vec(size_type n, const T &val = T()) { create(n, val); }
    template <class In>
    Vec(In begin, In end) { create(begin, end); }
    Vec(const Vec &v) { create(v.begin(), v.end()); }
    Vec &operator=(const Vec &);
    ~Vec()
    {
        uncreate();
        // std::cout << "Vec destructor called" << std::endl;
    }

    // operations
    size_type size() const
    {
        return avail - data;
    }

    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }

    void push_back(const T &val)
    {
        if (avail == limit) // get space if needed
            grow();
        unchecked_append(val); // append the new element
    }

    iterator erase(iterator);
    // iterator erase(iterator, iterator);

    void clear() { uncreate(); }

    // iterator operations
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    // friends
    friend std::ostream &operator<<(std::ostream &os, const Vec &v)
    {
        for (auto i = v.begin(); i != v.end(); ++i)
            os << *i << " ";
        return os;
    }

private:
    iterator data;
    iterator avail;
    iterator limit;

    // facilities for memory allocation
    std::allocator<T> alloc; // object to handle memory allocation

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T &);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T &);
};

template <class T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    // check for self-assignment
    if (&rhs != this)
    {
        // free the array in the left-hand side
        uncreate();
        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

// invariant
// 1. data points at our initial data element, if we have any, and is zero otherwise.
// 2. data <= avail <= limit.
// 3. Elements have been constructed in the range [data, avail).
// 4. Elements have not been constructed in the range [avail, limit).

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T &val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        // destroy (in reverse order) the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        // return all the space that was allocated
        alloc.deallocate(data, limit - data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow()
{
    // when growing, allocate twice as much space as currently in use
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

    // allocate 10 more space
    // size_type new_size = limit - data + 10;

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    // return the old space
    uncreate();
    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T>
void Vec<T>::unchecked_append(const T &val)
{
    alloc.construct(avail++, val);
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator it)
{
    if (it == avail)
        return it;
    for (iterator i = it; i != avail; ++i)
    {
        alloc.destroy(i);
        if (i + 1 != avail)
            alloc.construct(i, *(i + 1));
    }
    --avail;
    return it;
}

#endif // GUARD_VEC_H
