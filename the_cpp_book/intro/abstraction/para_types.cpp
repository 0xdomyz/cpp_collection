// g++ -o para_types para_types.cpp && ./para_types

#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

class Negative_size : public std::length_error
{
public:
    Negative_size() : std::length_error("Negative size") {}
};

template <typename T>
class Vector
{
private:
    T *elem; // elem points to an array of sz elements of type T
    int sz;

public:
    Vector(int s);               // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; } // destructor: release resources
    // ... copy and move operations ...
    T &operator[](int i);
    const T &operator[](int i) const;
    int size() const { return sz; };
    // begin() and end()
    T *begin();
    const T *begin() const;
    T *end();
    const T *end() const;
};

template <typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw Negative_size{};
    elem = new T[s];
    sz = s;
};

template <typename T>
const T &Vector<T>::operator[](int i) const
{
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
};

// begin implementation
template <typename T>
T *Vector<T>::begin()
{
    return &elem[0]; // pointer to first element
};

template <typename T>
const T *Vector<T>::begin() const
{
    return &elem[0]; // pointer to first element
};

// end implementation
template <typename T>
T *Vector<T>::end()
{
    return &elem[sz]; // pointer to one past the last element
};

template <typename T>
const T *Vector<T>::end() const
{
    return &elem[sz]; // pointer to one past the last element
};

// vector <string> functions
void write(const Vector<string> &vs) // Vector of some strings
{
    for (int i = 0; i != vs.size(); ++i)
        cout << vs[i] << '\n';
};

void f2(const Vector<string> &vs) // Vector of some strings
{
    for (auto &s : vs)
        cout << s << '\n';
};

int main(void)
{
    Vector<char> vc(200);      // vector of 200 characters
    Vector<string> vs(17);     // vector of 17 strings
    Vector<list<int>> vli(45); // vector of 45 lists of integers

    write(vs);

    f2(vs);

    return 0;
}