#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>

template <class T, class Ran>
T median(Ran begin, Ran end)
{

    if (begin == end)
    {
        throw std::domain_error("median of an empty container");
    }

    size_t size = end - begin;

    T *temp = new T[size];

    std::copy(begin, end, temp);
    std::sort(temp, temp + size);

    size_t mid = size / 2;
    T res = size % 2 == 0 ? (temp[mid] + temp[mid - 1]) / 2 : temp[mid];

    delete[] temp;

    return res;
}

#endif
