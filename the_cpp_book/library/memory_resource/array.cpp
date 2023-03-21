// g++ array.cpp -o array && ./array

#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

// template <typename T, siz e_t N> // an array of N Ts (§iso.23.3.2)
// struct array
// {
//     /*
//     types and operations like vector’s (§31.4),
//     except operations that change the container size, constructors, and assign() functions
//     */
//     void fill(const T &v); // assign N copies of v
//     void swap(array &) noexcept(noexcept(swap(declval<T &>(), declval<T &>())));
//     T __elem[N]; // implementation detail
// };

void f()
{
    array<string, 4> aa = {"Churchill", "Clare"};
    //
}

// array<int> ax = {1, 2, 3}; // error size not specified

array<int, 0> a0;

// void f(int n)
// {
//     array<string, n> aa = {"John's", "Queens' "}; // error : size not a constant expression
//     //
// }

void fill()
{
    array<int, 8> aa; // uninitialized, so far
    aa.fill(99);      // assign eight copies of 99
    // ...
}

void fc(int *p, int sz)
{
    for (int i = 0; i < sz; ++i)
        p[i] = 0;
}; // C-style interface

void g()
{
    array<int, 10> a;
    // fc(a, a.size());                        // error : no conversion
    fc(&a[0], a.size());                    // C-style use
    fc(a.data(), a.size());                 // C-style use
    auto p = find(a.begin(), a.end(), 777); // C++/STL-style use
    // ...
}

struct Shape
{
    virtual void draw() const = 0;
};

struct Circle : Shape
{
    void draw() const override { cout << "Circle::draw()" << endl; }
};

void h()
{
    Circle a1[10];
    array<Circle, 10> a2;
    // ...
    Shape *p1 = a1; // OK: disaster waiting to happen
    // Shape *p2 = a2; // error : no conversion of array<Circle,10> to Shape*
    // p1[3].draw();   // disaster
}

int main(void)
{
    array<int, 3> a1 = {1, 2, 3};

    f();

    fill();

    g();

    h();

    array<int, 7> a5 = {1, 2, 3, 5, 8, 13, 25};
    auto x1 = get<5>(a5);                                  // 13
    auto x2 = a5[5];                                       // 13
    auto sz = tuple_size<decltype(a5)>::value;             // 7
    typename tuple_element<5, decltype(a5)>::type x3 = 13; // x3 is an in

    return 0;
}