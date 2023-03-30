// Compile and run: g++ meantaining_invariants.cpp -o meantaining_invariants && ./meantaining_invariants

#include <iostream>
#include <vector>

using namespace std;

struct Z
{ // invariant:
    // my_favor ite is the index of my favor ite element of elem
    // largest points to the element with the highest value in elem
    vector<int> elem;
    int my_favorite;
    int *largest;
};

Z v0; // no initialization (oops! possibility of undefined values)
// Z val{{1, 2, 3}, 1, &val[2]}; // OK, but ugly and error-prone
Z val{{1, 2, 3}, 1, &val.elem[2]}; // OK, but ugly and error-prone
Z v2 = val;                        // copies: v2.largest points into val
Z v3 = move(val);                  // moves: val.elem becomes empty; v3.my_favor ite is out of rang

int main(void)
{
    return 0;
}