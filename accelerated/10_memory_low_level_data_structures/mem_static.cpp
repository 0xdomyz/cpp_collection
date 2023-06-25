// g++ mem_static.cpp -o mem_static && ./mem_static

#include <iostream>

using namespace std;

// This function is completely legitimate.
int *pointer_to_static()
{
    static int x;
    return &x;
}

int main()
{
    int *p = pointer_to_static();
    cout << *p << endl;
    *p = 7;
    cout << *p << endl;

    int *p2 = pointer_to_static();
    cout << *p2 << endl;
}