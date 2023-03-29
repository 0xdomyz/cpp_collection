// Compile and run: g++ copy.cpp -o copy && ./copy

#include <array>

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
    Matrix(Matrix &&);                 // move constr uctor
    Matrix &operator=(Matrix &&);      // move assignment
    ~Matrix() { delete[] elem; }
    // ...
};

template <class T>
Matrix<T>::Matrix(const Matrix &m) // copy constr uctor
    : dim{m.dim},
      elem{new T[m.size()]}
{
    uninitialized_copy(m.elem, m.elem + m.size(), elem); // copy elements
}

template <class T>
// Matrix &Matrix::operator=(const Matrix &m) // copy assignment
// {
//     if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
//         throw runtime_error("bad size in Matrix =");
//     copy(m.elem, m.elem + m.size(), elem); // copy elements
// }
Matrix<T> &Matrix<T>::operator=(const Matrix &m) // copy assignment
{
    Matrix tmp{m};    // make a copy
    swap(tmp, *this); // swap tmp’s representation with *this’s
    return *this;
}

int main(void) {}