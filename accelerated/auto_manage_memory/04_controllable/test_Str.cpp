// g++ test_Str.cpp -o test_Str && ./test_Str

#include <iostream>
#include "Str.h"

using namespace std;

int main(void)
{
    const char *cp = "hello";
    Str s1(cp);
    Str s2(3, 'a');
    Str s3 = s1 + Str() + "!" + Str(" ") + s2 + Str(cp, cp + 3);
    s2 = s3;
    s2[0] = 'H';

    cout << s2 << endl;
    cout << s3 << endl;

    return 0;
}