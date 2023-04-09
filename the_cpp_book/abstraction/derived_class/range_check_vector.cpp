// compile and run: g++ -o range_check_vector range_check_vector.cpp && ./range_check_vector

#include <vector>
#include <iostream>

using namespace std;
using size_type = std::size_t;

class Bad_index
{
    int i;

public:
    Bad_index(int ii) : i(ii) {}
    int index() const { return i; }
};

template <class T>
struct Vector : std::vector<T>
{
    using vector<T>::vector; // inherit constr uctors
    void check(size_type i) const
    {
        if (this->size() < i)
            throw Bad_index(i);
    }
    T &operator[](size_type i)
    {
        check(i);
        return vector<T>::operator[](i);
    }
    const T &operator[](size_type i) const
    {
        check(i);
        return vector<T>::operator[](i);
    }
    // const version, it is necessary to avoid ambiguity
    // when using the subscript operator with a const object
};

int main()
{
    Vector<int> v{1, 2, 3, 5, 8}; // OK: use initializer-list constructor from std::vector
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << "\n";

    const Vector<int> cv{1, 2, 3, 5, 8};
    for (int i = 0; i < cv.size() * 2; ++i)
        cout << cv[i] << "\n";

    return 0;
}