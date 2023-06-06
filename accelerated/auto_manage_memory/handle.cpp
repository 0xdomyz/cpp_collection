#include "handle.h"
#include <stdexcept>

using namespace std;

template <class T>
T &Handle<T>::operator*() const
{
    if (p)
        return *p;
    throw runtime_error("unbound Handle");
}
template <class T>
T *Handle<T>::operator->() const
{
    if (p)
        return p;
    throw runtime_error("unbound Handle");
}