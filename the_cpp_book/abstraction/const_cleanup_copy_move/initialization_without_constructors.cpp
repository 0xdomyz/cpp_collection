// Compile and run: g++ initialization_without_constructors.cpp -o initialization_without_constructors && ./initialization_without_constructors

#include <iostream>
#include <string>

using namespace std;

struct Work
{
    string author;
    string name;
    int year;
};
Work s9{"Beethoven",
        "Symphony No. 9 in D minor, Op. 125; Choral",
        1824};              // memberwise initialization
Work currently_playing{s9}; // copy initialization
Work none{};                // default initialization

struct Buf
{
    int count;
    char buf[16 * 1024];
};

Buf buf0; // statically allocated, so initialized by default
void f()
{
    Buf buf1;             // leave elements uninitialized
    Buf buf2{};           // I really want to zero out those elements
    int *p1 = new int;    // *p1 is uninitialized
    int *p2 = new int{};  // *p2 == 0
    int *p3 = new int{7}; // *p3 == 7
    // ...
}

template <class T>
class Checked_pointer
{ // control access to T* member
public:
    T &operator*(); // check for nullptr and return value
    // ...
};
// Checked_pointer<int> p{new int{7}}; // error : can’t access p.p

int main(void)
{
    return 0;
}