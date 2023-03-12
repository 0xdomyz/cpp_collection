// g++ -std=c++17 -o abstract_type abstract_type.cpp && ./abstract_type

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

// Vector concrete type
class Vector
{
    int sz;
    double *elem;

public:
    Vector(int s) : sz{s}, elem{new double[s]} // constructor: acquire resources
    {
        for (int i = 0; i != s; ++i)
            elem[i] = 0;
    }

    ~Vector() { delete[] elem; } // destructor: release resources

    double &operator[](int i) { return elem[i]; } // access: read and write
    int size() const { return sz; }
    // begin
    double *begin() const { return elem; }
};

class Container
{
public:
    virtual double &operator[](int) = 0; // pure virtual function
    virtual int size() const = 0;        // const member function (§3.2.1.1)
    virtual ~Container() {}              // destructor (§3.2.1.2)
};

// virtual function
void use(Container &c)
{
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
}

class Vector_container : public Container
{ // Vector_container implements Container
    Vector v;

public:
    Vector_container(int s) : v(s) {} // Vector of s elements
    ~Vector_container() {}
    Vector_container(initializer_list<double> lst) : v(lst.size())
    {
        copy(lst.begin(), lst.end(), v.begin());
    }
    double &operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

void g()
{
    Vector_container vc{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    use(vc);
}

// List container
class List_container : public Container
{                    // List_container implements Container
    list<double> ld; // (standard-librar y) list of doubles (§4.4.2)
public:
    List_container() {} // empty List
    List_container(initializer_list<double> il) : ld{il} {}
    ~List_container() {}
    double &operator[](int i);
    int size() const { return ld.size(); }
};
double &List_container::operator[](int i)
{
    for (auto &x : ld)
    {
        if (i == 0)
            return x;
        --i;
    }
    throw out_of_range("List container");
}

void h()
{
    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    use(lc);
}

int main(void)
{
    g();
    h();
}