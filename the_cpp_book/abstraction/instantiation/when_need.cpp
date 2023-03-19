// g++ when_need.cpp -o when_need -std=c++11 && ./when_need

#include <iostream>
#include <string>

using namespace std;

class X;
X *p; // OK: no definition of X needed
// X a;  // error : definition of X needed

template <typename T>
class Link
{
    Link *suc; // OK: no definition of Link needed (yet)
    // ...
};
Link<int> *pl; // no instantiation of Link<int> needed (yet)
Link<int> lnk; // now we need to instantiate Link<int>

template <typename T>
class List
{
    // ...
public:
    void sort(){
        // ...
    };
};
class Glob
{
    // ... no comparison operators ...
};
void f(List<Glob> &lb, List<string> &ls)
{
    ls.sort();
    // ... use operations on lb, but not lb.sor t() ...
}

int main(void)
{
    // ...
}
