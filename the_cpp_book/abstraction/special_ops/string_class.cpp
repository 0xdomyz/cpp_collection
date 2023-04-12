// g++ string_class.cpp -o string_class && ./string_class

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

using namespace std;

class String
{
    /*
    A simple string that implements the short str ing optimization
    size()==sz is the number of elements
    if size()<= short_max, the characters are held in the String object itself;
    otherwise the free store is used.
    ptr points to the start of the character sequence
    the character sequence is kept zero-ter minated: ptr[size()]==0;
    this allows us to use C librar y str ing functions and to easily return a C-style string: c_str()
    To allow efficient addition of characters at end, String grows by doubling its allocation;
    capacity() is the amount of space available for characters
    (excluding the terminating 0): sz+space
    */

public:
    String();                          // default constructor : x{""}
    explicit String(const char *p);    // constructor from C-style string: x{"Euler"}
    String(const String &);            // copy constr uctor
    String &operator=(const String &); // copy assignment
    String(String &&x);                // move constr uctor
    String &operator=(String &&x);     // move assignment
    ~String()
    {
        if (short_max < sz)
            delete[] ptr;
    }                                          // destructor
    char &operator[](int n) { return ptr[n]; } // unchecked element access
    char operator[](int n) const { return ptr[n]; }
    char &at(int n)
    {
        check(n);
        return ptr[n];
    } // range-checked element access
    char at(int n) const
    {
        check(n);
        return ptr[n];
    }
    String &operator+=(char c);         // add c at end
    const char *c_str() { return ptr; } // C-style string access
    const char *c_str() const { return ptr; }
    int size() const { return sz; } // number of elements
    int capacity() const            // elements
    {
        return (sz <= short_max) ? short_max : sz + space;
    }

private:
    static const int short_max = 15;
    int sz; // number of characters
    char *ptr;
    union
    {
        int space;              // unused allocated space
        char ch[short_max + 1]; // leave space for terminating 0
    };
    void check(int n) const // range check
    {
        if (n < 0 || sz <= n)
            throw std::out_of_range("String::at()");
    }
    // ancillar y member functions:
    void copy_from(const String &x);
    void move_from(String &x);
};

// ancillary

char *expand(const char *ptr, int n) // expand into free store
{
    char *p = new char[n];
    // strcpy(p, ptr); // §43.4 todo
    return p;
}

void String::copy_from(const String &x)
// make *this a copy of x
{
    if (x.sz <= short_max)
    { // copy *this
        // memcpy(this, &x, sizeof(x)); // §43.5 todo
        ptr = ch;
    }
    else
    { // copy the elements
        ptr = expand(x.ptr, x.sz + 1);
        sz = x.sz;
        space = 0;
    }
}

void String::move_from(String &x)
{
    if (x.sz <= short_max)
    { // copy *this
        // memcpy(this, &x, sizeof(x)); // §43.5 todo
        ptr = ch;
    }
    else
    { // grab the elements
        ptr = x.ptr;
        sz = x.sz;
        space = x.space;
        x.ptr = x.ch; // x = ""
        x.sz = 0;
        x.ch[0] = 0;
    }
}

// usages
int hash(const String &s)
{
    int h{s[0]};
    for (int i{1}; i != s.size(); i++)
        h ^= s[i] >> 1; // unchecked access to s
    return h;
}

void print_in_order(const String &s, const vector<int> &index)
{
    for (auto x : index)
        cout << s.at(x) << '\n';
}

int main(void) {}