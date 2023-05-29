#ifndef GUARD_VEC_H
#define GUARD_VEC_H

template <class T>
class Vec
{
public:
    // interface
private:
    T *data;  // first element in the Vec
    T *limit; // one past the last element in the Vec
};

#endif // GUARD_VEC_H