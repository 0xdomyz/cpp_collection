#include <iostream>
#include <string>
#include "vec.h"

using namespace std;

int main(void)
{
    // construct a Vec
    Vec<string> vs;     // empty Vec
    Vec<double> v(100); // Vec with 100 elements
    // obtain the names of the types used by the Vec
    Vec<string>::const_iterator b, e;
    Vec<string>::size_type i = 0;
    // use size and the index operator to look at each element in the Vec
    for (i = 0; i != vs.size(); ++i)
        cout << vs[i].name();
    // return iterators positioned on the first and one past the last element
    b = vs.begin();
    e = vs.end();
}