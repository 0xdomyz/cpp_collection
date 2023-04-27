#include "matrix.h"

template <typename T, size_t N>
template <typename... Exts>
Matrix<T, N>::Matrix(Exts... exts)
    : desc{exts...},   // copy extents
      elems(desc.size) // allocate desc.size elements and default initialize them
{
}

template <typename T, size_t N>
Matrix<T, N>::Matrix(Matrix_initializer<T, N> init)
{
    Matrix_impl::derive_extents(init, desc.extents); // deduce extents from initializer list (§29.4.4)
    elems.reserve(desc.size);                        // make room for slices
    Matrix_impl::insert_flat(init, elems);           // initialize from initializer list (§29.4.4)
    assert(elems.size() == desc.size);
}

template <typename T, size_t N>
template <typename U>
Matrix<T, N>::Matrix(const Matrix_ref<U, N> &x)
    : desc{x.desc}, elems{x.begin(), x.end()} // copy desc and elements
{
    static_assert(Convertible<U, T>(), "Matrix constructor: incompatible element types");
}

// copy assignment
template <typename T, size_t N>
template <typename U>
Matrix<T, N> &Matrix<T, N>::operator=(const Matrix_ref<U, N> &x)
{
    static_assert(Convertible<U, T>(), "Matrix =: incompatible element types");
    desc = x.desc;
    elems.assign(x.begin(), x.end());
    return *this;
}