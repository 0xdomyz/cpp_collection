#include <iostream>
#include <vector>

using namespace std;

namespace matrix
{

    template <typename T, size_t N>
    class Matrix
    {
    public:
        static constexpr size_t order = N;
        using value_type = T;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        Matrix() = default;
        Matrix(Matrix &&) = default; // move
        Matrix &operator=(Matrix &&) = default;
        Matrix(Matrix const &) = default; // copy
        Matrix &operator=(Matrix const &) = default;
        ~Matrix() = default;
        template <typename U>
        Matrix(const Matrix_ref<U, N> &); // construct from Matrix_ref
        template <typename U>
        Matrix &operator=(const Matrix_ref<U, N> &); // assign from Matrix_ref
        template <typename... Exts>                  // specify the extents
        explicit Matrix(Exts... exts);
        Matrix(Matrix_initializer<T, N>);            // initialize from list
        Matrix &operator=(Matrix_initializer<T, N>); // assign from list
        template <typename U>
        Matrix(initializer_list<U>) = delete; // don’t use {} except for elements
        template <typename U>
        Matrix &operator=(initializer_list<U>) = delete;
        static constexpr size_t order() { return N; }              // number of dimensions
        size_t extent(size_t n) const { return desc.extents[n]; }  // #elements in the nth dimension
        size_t siz e() const { return elems.size(); }              // total number of elements
        const Matrix_slice<N> &descriptor() const { return desc; } // the slice defining subscripting
        T *data() { return elems.data(); }                         // ‘‘flat’’ element access
        const T *data() const { return elems.data(); }
        // ...
    private:
        Matrix_slice<N> desc; // slice defining extents in the N dimensions
        vector<T> elems;      // the elements
    };

}
