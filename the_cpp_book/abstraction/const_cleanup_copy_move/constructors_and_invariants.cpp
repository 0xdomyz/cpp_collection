// Compile and run: g++ constructors_and_invariants.cpp -o constructors_and_invariants && ./constructors_and_invariants

#include <iostream>
#include <stdexcept>

using namespace std;

class Vector2
{
public:
    Vector2(int s);
    // ...
};

struct S
{
    S(); // fine
    // void S(int); // error : no type can be specified for a constructor
    // int S;       // error : the class name must denote a constructor
    // enum S
    // {
    //     foo,
    //     bar
    // }; // error : the class name must denote a constructor
};

class Vector
{
public:
    Vector(int s);
    // ...
private:
    double *elem; // elem points to an array of sz doubles
    int sz;       // sz is non-negative
};

class Bad_size
{
public:
    Bad_size(int s) : size{s} {}
    int size;
};

Vector::Vector(int s)
{
    if (s < 0)
        throw Bad_size{s};
    sz = s;
    elem = new double[s];
}

int main(void)
{
    Vector v(10);
    return 0;
}