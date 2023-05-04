// compile: g++ -o test test.cpp median.cpp && ./test
// seperate compilation: g++ -c median.cpp && g++ -c test.cpp && g++ -o test test.o median.o && ./test

#include "median.h"
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<double> v;
    v.push_back(1.0);
    v.push_back(2.0);
    v.push_back(3.0);
    cout << median(v) << endl;
    return 0;
}
