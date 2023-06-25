// g++ default_assignment_vec.cpp -o default_assignment_vec && ./default_assignment_vec

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X
{
    int a;
    string b;
    vector<float> c;
};

struct Y
{
    int a;
    string b;
    vector<float> c;
    Y() : a(0), b(""), c(vector<float>()) {}
};

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
        os << *it << " ";
    return os;
}

int main()
{
    cout << "Default constructor for POD" << endl;
    X x;
    cout << x.a << endl;
    cout << x.b << endl;
    cout << x.c << endl;

    cout << "Sythesized destructor" << endl;
    int *ip;
    string *sp;
    vector<float> *vp;
    {
        X x;
        x.a = 1;
        x.b = "hello";
        x.c.push_back(3.0);

        ip = &x.a;
        sp = &x.b;
        vp = &x.c;
    } // x is destroyed here
    cout << "is the int destroyed?" << endl;
    cout << *ip << endl;
    cout << "is the string destroyed?" << endl;
    cout << *sp << endl;
    cout << "is the vector destroyed?" << endl;
    cout << *vp << endl;

    cout << "Default constructor as defined" << endl;
    Y y;
    cout << y.a << endl;
    cout << y.b << endl;
    cout << y.c << endl;

    Y y2;
    y2.a = 1;
    y2.b = "hello";
    y2.c.push_back(3.0);

    cout << "Assignment operator" << endl;
    y = y2;
    cout << y.a << endl;
    cout << y.b << endl;
    cout << y.c << endl;

    y.c.push_back(4.0);

    cout << "is the old object changed?" << endl;
    cout << y2.c << endl;
}
