// compile: g++ -o test_median test_median.cpp median.cpp && ./test_median
// seperate compilation: g++ -c median.cpp && g++ -c test_median.cpp && g++ -o test_median test_median.o median.o && ./test_median

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
