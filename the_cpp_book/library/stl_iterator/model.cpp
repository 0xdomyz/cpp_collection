// g++ model.cpp -o model && ./model

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Iter>
void forward(Iter p, int n)
{
    while (n > 0)
        *p++ = --n;
}
void user()
{
    vector<int> v(10);
    forward(v.begin(), v.size()); // OK
    for (auto x : v)
        cout << x << endl;
    // forward(v.begin(), 1000);     // big trouble
}

int main(void)
{
    const char *s = "Hello";
    const char *b = s;             // begin
    const char *e = s + strlen(s); // end

    while (b != e)
    { // use != rather than <
        // do something
        cout << *b << endl;
        ++b; // go to next element
    }

    vector<int> v = {1, 2, 3, 4, 5};
    int x = 3;

    auto p = find(v.begin(), v.end(), x); // look for x in v
    if (p != v.end())
    {
        // x found at p
        cout << *p << endl;
    }
    else
    {
        // x not found in [v.begin():v.end())
        cout << "not found" << endl;
    }

    cout << "user" << endl;
    user();

    return 0;
}