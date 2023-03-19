// wip
// g++ type_func.cpp -o type_func -std=c++11 && ./type_func

#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <memory>

using namespace std;

enum class Axis : char
{
    x,
    y,
    z
};

enum flags
{
    off,
    x = 1,
    y = x << 1,
    z = x << 2,
    t = x << 3
};

template <typename T, int N>
struct Array_type
{
    using type = T;
    static const int dim = N;
    // ...
};

// template <int N>
// struct Integer
// {
//     using Error = void;
//     using type = Select<N, Error, signed char, short, Error, int, Error, Error, Error, long>;
// };

template <typename T>
struct On_heap
{
    On_heap() : p(new T) {}  // allocate
    ~On_heap() { delete p; } // deallocate
    T &operator*() { return *p; }
    T *operator->() { return p; }
    On_heap(const On_heap &) = delete; // prevent copying
    On_heap operator=(const On_heap &) = delete;

private:
    T *p; // pointer to object on the free store
};

template <typename T>
struct Scoped
{
    T &operator*() { return x; }
    T *operator->() { return &x; }
    Scoped(const Scoped &) = delete; // prevent copying
    Scoped operator=(const Scoped &) = delete;

private:
    T x; // the object
};

constexpr int on_stack_max = sizeof(std::string); // max size of object we want on the stack
template <typename T>
struct Obj_holder
{
    using type = typename std::conditional<(sizeof(T) <= on_stack_max),
                                           Scoped<T>, // first alternative
                                           On_heap<T> // second alternative
                                           >::type;
};

// void f()
// {
//     typename Obj_holder<double>::type v1;             // the double goes on the stack
//     typename Obj_holder<array<double, 200>>::type v2; // the array goes on the free store
//     // ...
//     *v1 = 7.7;    // Scoped provides pointer-like access (* and [])
//     v2[77] = 9.9; // On_heap provides pointer-like access (* and [])
//     // ...
// }

int main(void)
{
    if (is_polymorphic<int>::value)
        cout << "Big surprise!";
    typename std::underlying_type<Axis>::type x; // x is a char
    typename std::underlying_type<Axis>::type y; // y is probably an int (§8.4.2)

    using Array = Array_type<int, 3>;
    Array::type x2;               // x2 is an int
    constexpr int s = Array::dim; // s is 3

    // typename Integer<4>::type i4 = 8; // 4-byte integer
    // typename Integer<1>::type i1 = 9; // 1-byte integer
};