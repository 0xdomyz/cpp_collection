// Compile and run: g++ move.cpp -o move && ./move

#include <string>
#include <vector>
#include <array>

using namespace std;

template <class T>
void swap(T &a, T &b)
{
    const T tmp = a; // put a copy of a into tmp
    a = b;           // put a copy of b into a
    b = tmp;         // put a copy of tmp into b
};

template <class T>
class Matrix
{
public:
    std::array<int, 2> dim;
    T *elem; // pointer to sz elements of type T

    Matrix(int d1, int d2) : dim{d1, d2}, elem{new T[d1 * d2]} {}
    int size() const { return dim[0] * dim[1]; }
    Matrix operator+(const Matrix &);
    Matrix(const Matrix &);            // copy constr uctor
    Matrix(Matrix &&);                 // move constr uctor
    Matrix &operator=(const Matrix &); // copy assignment
    Matrix &operator=(Matrix &&);      // move assignment
    ~Matrix();                         // destructor
    // ...
};

template <class T>
Matrix<T>::Matrix(Matrix &&a)  // move constr uctor
    : dim{a.dim}, elem{a.elem} // grab a’s representation
{
    a.dim = {0, 0}; // clear a’s representation
    a.elem = nullptr;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(Matrix &&a) // move assignment
{
    swap(dim, a.dim); // swap representations
    swap(elem, a.elem);
    return *this;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &a, const Matrix<T> &b)
// res[i][j] = a[i][j]+b[i][j] for each i and j
{
    if (a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1])
        throw std::runtime_error("unequal Matrix sizes in +");
    Matrix<T> res{a.dim[0], a.dim[1]};
    constexpr auto n = a.size();
    for (int i = 0; i != n; ++i)
        res.elem[i] = a.elem[i] + b.elem[i];
    return res;
}

// Matrix &operator+(const Matrix &a, const Matrix &b) // beware!
// {
//     Matrix &res = *new Matrix; // allocate on free store
//     // res[i][j] = a[i][j]+b[i][j] for each i and j
//     return res;
// }

template <class T>
void f(string &s1, string &s2,
       vector<string> &vs1, vector<string> &vs2,
       Matrix<T> &m1, Matrix<T> &m2)
{
    swap(s1, s2);
    swap(vs1, vs2);
    swap(m1, m2);
}

template <class T>
void swap2(T &a, T &b) // "perfect swap" (almost)
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main(void) {}