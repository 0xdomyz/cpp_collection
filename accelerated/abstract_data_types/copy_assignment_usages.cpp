// g++ -o copy_assignment_usages copy_assignment_usages.cpp && ./copy_assignment_usages

#include <iostream>

using namespace std;

struct X
{
    // default cons
    X() : internal(0) { cout << "default cons" << endl; }
    // copy cons
    X(const X &x) : internal(x.internal) { cout << "copy cons" << endl; }
    // copy assignment
    X &operator=(const X &x)
    {
        cout << "copy assignment" << endl;
        internal = x.internal;
        return *this;
    }
    // destructor
    ~X() { cout << "destructor" << endl; }

    int internal;
};

X by_values_function(X x)
{
    cout << "by_values_function" << endl;
    return x;
}

X &by_reference_function(X &x)
{
    cout << "by_reference_function" << endl;
    return x;
}

int main(void)
{
    // default cons
    X x1;
    cout << "x1.internal: " << x1.internal << endl;
    cout << endl;

    // copy cons
    X x2(x1);
    cout << "x2.internal: " << x2.internal << endl;
    X x3 = x1;
    cout << "x3.internal: " << x3.internal << endl;
    cout << endl;

    // copy assignment
    x3 = x2;
    cout << "x3.internal: " << x3.internal << endl;
    cout << endl;

    // call by_values_function
    X x4 = by_values_function(x1);
    cout << "x4.internal: " << x4.internal << endl;
    cout << endl;

    // call by_reference_function
    X x5 = by_reference_function(x1);
    cout << "x5.internal: " << x5.internal << endl;
    cout << endl;

    return 0;
}
