// Compile and run: g++ copy.cpp -o copy && ./copy

#include <array>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

template <class T>
class Matrix
{
    array<int, 2> dim; // two dimensions
    T *elem;           // pointer to dim[0]*dim[1] elements of type T
public:
    Matrix(int d1, int d2) : dim{d1, d2}, elem{new T[d1 * d2]} {} // simplified (no error handling)
    int size() const { return dim[0] * dim[1]; }
    Matrix(const Matrix &);            // copy constr uctor
    Matrix &operator=(const Matrix &); // copy assignment
    // Matrix(Matrix &&);                 // move constr uctor
    // Matrix &operator=(Matrix &&);      // move assignment
    ~Matrix() { delete[] elem; }
    // ...
};

template <class T>
Matrix<T>::Matrix(const Matrix<T> &m) // copy constr uctor
    : dim{m.dim},
      elem{new T[m.size()]}
{
    uninitialized_copy(m.elem, m.elem + m.size(), elem); // copy elements
    // prototype: uninitialized_copy(b,e,o) where b and e denote input iterators
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &m) // copy assignment
{
    if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
        throw runtime_error("bad size in Matrix =");
    copy(m.elem, m.elem + m.size(), elem); // copy elements
    // prototype: copy(b,e,o) where b and e denote input iterators
    return *this;
}

// template <class T>
// Matrix<T> &Matrix<T>::operator=(const Matrix &m) // copy assignment
// {
//     Matrix<T> tmp{m}; // make a copy
//     swap(tmp, *this); // swap tmp’s representation with *this’s
//                       // prototype: swap(a,b) where a and b are of the same type
//     return *this;
// }

int main(void)
{
    Matrix<int> m1{2, 3}; // initialize m1
    Matrix<int> m2{m1};   // copy constr uction

    cout << "m1: " << m1.size() << endl;
    cout << "m2: " << m2.size() << endl;

    Matrix<int> m3{2, 3}; // initialize m3
    m3 = m1;              // copy assignment

    cout << "m3: " << m3.size() << endl;

    return 0;
}