// compile and run: g++ -o basic basic.cpp && ./basic

#include <iostream>

using namespace std;

class X
{
private: // the representation (implementation) is private
    int m;

public:                    // the user interface is public
    X(int i = 0) : m{i} {} // a constr uctor (initialize the data member m)
    int mf(int i)          // a member function
    {
        int old = m;
        m = i;      // set a new value
        return old; // return the old value
    }
};

int user(X var, X *ptr)
{
    int x = var.mf(7);  // access using . (dot)
    int y = ptr->mf(9); // access using -> (arrow)
    // int z = var.m;      // error : cannot access private member
    cout << "var.mf(7) returned " << x << endl;
    cout << "ptr->mf(9) returned " << y << endl;
    return x + y;
}

int main(void)
{

    X var{7};      // a var iable of type X, initialized to 7
    X *ptr = &var; // a pointer to X, initialized to the address of var
    user(var, ptr);
    return 0;
}