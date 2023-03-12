// g++ -o aliases aliases.cpp && ./aliases

#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
class Vector
{
    T *elem;
    int sz;

public:
    using value_type = T;
    int size() const { return sz; }
    T &operator[](int i) { return elem[i]; }
    const T &operator[](int i) const { return elem[i]; }
    // constructor, destructor, copy, move, assignment
    Vector(std::initializer_list<T> lst)
        : elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }
    ~Vector() { delete[] elem; }
    Vector(const Vector &a)
        : elem{new T[a.sz]}, sz{a.sz}
    {
        std::copy(a.elem, a.elem + sz, elem);
    }
    Vector &operator=(const Vector &a)
    {
        T *p = new T[a.sz];
        std::copy(a.elem, a.elem + a.sz, p);
        delete[] elem;
        elem = p;
        sz = a.sz;
        return *this;
    }
};

template <typename Container>
void algo(Container &c)
{
    typename Container::value_type x; // x is of type Container::value_type

    using T = typename Container::value_type;

    // Vector of type x
    Vector<T> v3{1, 2, 3, 4, 5, 6};

    v3[0] = c[2];

    cout << "v3[0] = " << v3[0] << endl;
}

int main()
{
    Vector<int> v{1, 2, 3, 4, 5, 6};
    for (int i = 0; i != v.size(); ++i)
        std::cout << v[i] << '\n';

    Vector<int> v2{1, 2, 3, 4, 5, 6};
    algo(v2);
}
