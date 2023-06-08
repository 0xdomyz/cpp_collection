// g++ test_Str.cpp -o test_Str && ./test_Str

#include <iostream>
#include "Str.h"

using namespace std;

int main(void)
{
    Str s1 = "hello ";
    Str s2 = "world";
    Str s3 = s1 + s2;
    cout << s3 << endl;
    return 0;
}