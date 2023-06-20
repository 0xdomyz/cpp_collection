// g++ test_getline.cpp str.cpp -o test_getline && ./test_getline < test_getline.cpp

#include <iostream>
#include "str.h"

using namespace std;

int main()
{
    Str s;
    while (s.getline(cin))
    {
        cout << s << endl;
    }

    {
        cout << "with checking cin:" << endl;
        double x;
        if (cin)
        {
            cin >> x;
            cout << x << endl;
        }
    }

    {
        cout << "without checking cin:" << endl;
        double x;
        cin >> x;
        cout << x << endl;
    }

    return 0;
}
