// g++ mem_auto.cpp -o mem_auto && ./mem_auto

#include <iostream>

using namespace std;

// this function deliberately yields an invalid pointer.
// it is intended as a negative example—don't do this!
int *invalid_pointer()
{
    int x;
    return &x; // instant disaster!
}

int main()
{
    int *p = invalid_pointer();
    cout << *p << endl;
    *p = 7; // disaster has already struck!
    cout << *p << endl;
}