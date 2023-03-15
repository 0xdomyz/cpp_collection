// compile and run:  g++ -o algo_overview algo_overview.cpp && ./algo_overview

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

vector<int> vec{47, 12, 25, 64, 1, 12, 3, 71, 8, 9};

// define b, e, x
auto b = vec.begin();
auto e = vec.end();
auto x = 12;

// create a function f
auto f = [](int a)
{
    return a > 10;
};

// define v, v2
auto v = 12;
auto v2 = 42;

int main(void)
{
    auto p = find(b, e, x); // p is the first p in [b:e) so that ∗p==x
    cout << "p = " << *p << endl;

    p = find_if(b, e, f); // p is the first p in [b:e) so that f(∗p)==true
    cout << "p = " << *p << endl;

    auto n = count(b, e, x); // n is the number of elements ∗q in [b:e) so that ∗q==x
    cout << "n = " << n << endl;

    n = count_if(b, e, f); // n is the number of elements ∗q in [b:e) so that f(∗q,x)
    cout << "n = " << n << endl;

    replace(b, e, v, v2); // Replace elements ∗q in [b:e) so that ∗q==v by v2
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    replace_if(b, e, f, v2); // Replace elements ∗q in [b:e) so that f(∗q) by v2
    for (auto x : vec)
        cout << x << " ";
    cout << endl;

    // todo
    // auto length = distance(b, e); // length is the number of elements in [b:e)
    // vector<int> out(length + 1);
    // auto p2 = copy(b, e, out); // Copy [b:e) to [out:p)
    // cout << "out = ";
    // for (auto x : out)
    //     cout << x << " ";
    // cout << endl;

    // p = copy_if(b, e, out, f);       // Copy elements ∗q from [b:e) so that f(∗q) to [out:p)
    // p = unique_copy(b, e, out);      // Copy [b:e) to [out:p); don’t copy adjacent duplicates
    // sort(b, e);                      // Sort elements of [b:e) using < as the sorting criterion
    // sort(b, e, f);                   // Sort elements of [b:e) using f as the sorting criterion
    // (p1, p2) = equal_range(b, e, v); //[p1:p2) is the subsequence of the sorted sequence [b:e) with the value v; basically a binary search for v
    // p = merge(b, e, b2, e2, out);    // Merge two sorted sequences [b:e) and [b2:e2) into [out:p)
}
