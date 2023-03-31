// Compile and run: g++ use_of_initializer_lists.cpp -o use_of_initializer_lists && ./use_of_initializer_lists

#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

void f(initializer_list<int> args)
{
    for (int i = 0; i != args.size(); ++i)
        cout << args.begin()[i] << "\n";
}

void f2(initializer_list<int> args)
{
    for (auto p = args.begin(); p != args.end(); ++p)
        cout << *p << "\n";
}

void f3(initializer_list<int> args)
{
    for (auto x : args)
        cout << x << "\n";
}

int f4(std::initializer_list<int> x, int val)
{
    // *x.begin() = val;  // error : attempt to change the value of an initializer-list element
    return *x.begin(); // OK
}

void g()
{
    for (int i = 0; i != 10; ++i)
        cout << i << '\n';
}

template <class E>
class Vector
{
public:
    Vector(std::initializer_list<E> s); // initializer-list constructor
    // ...
private:
    int sz;
    E *elem;
};

template <class E>
Vector<E>::Vector(std::initializer_list<E> s)
    : sz{s.size()} // set vector size
{
    // get size of mem for elem
    elem = new E[s.size()];                       // allocate memory for elements
    uninitialized_copy(s.begin(), s.end(), elem); // initialize elements in elem[0:s.size())
}

int main(void) {}