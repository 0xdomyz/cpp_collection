// g++ -o structures structures.cpp -std=c++11 && ./structures

#include <iostream>

using namespace std;

struct Vector
{
    int sz;       // number of elements
    double *elem; // pointer to elements
};

void vector_init(Vector &v, int s)
{
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s;
}

double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v, s); // allocate s elements for v
    for (int i = 0; i != s; ++i)
        cin >> v.elem[i]; // read into elements
    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i]; // take the sum of the elements
    return sum;
}

void f(Vector v, Vector &rv, Vector *pv)
{
    int i1 = v.sz;   // access through name
    int i2 = rv.sz;  // access through reference
    int i4 = pv->sz; // access through pointer
}

int main()
{
    Vector v;
    vector_init(v, 3); // allocate 3 elements for v
    for (int i = 0; i != v.sz; ++i)
        v.elem[i] = 1; // put 1 in each element

    Vector v2;
    cout << "enter 3 numbers: \n";
    double sum = read_and_sum(3);
    cout << "the sum is: " << sum << '\n';

    f(v, v, &v2);
}