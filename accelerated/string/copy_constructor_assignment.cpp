// g++ copy_constructor_assignment.cpp -o copy_constructor_assignment && ./copy_constructor_assignment

#include <iostream>
using namespace std;

class Example
{
public:
    int x;
    Example() {}   // Default constructor
    Example(int x) // Constructor
    {
        this->x = x;
    }
    Example(const Example &e) // Copy constructor
    {
        cout << "Copy constructor called" << endl;
        x = e.x;
    }
    // copy assignment
    Example &operator=(const Example &e)
    {
        cout << "Copy assignment called" << endl;
        x = e.x;
        return *this;
    }
};

int main()
{
    Example e1(10);
    Example e2 = e1;      // Copy constructor called
    cout << e2.x << endl; // Output: 10
    Example e3;
    e3 = e1; // Copy assignment called
    return 0;
}