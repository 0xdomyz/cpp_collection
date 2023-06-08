// g++ test_ref_handle.cpp -o test_ref_handle && ./test_ref_handle

#include "ref_handle.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    Ref_handle<string> r1(new string("hello"));
    Ref_handle<string> r2(r1);

    cout << "r1: " << *r1 << endl;
    cout << "r2: " << *r2 << endl;

    *r1 = "world";

    cout << "r1: " << *r1 << endl;
    cout << "r2: " << *r2 << endl;

    return 0;
}
