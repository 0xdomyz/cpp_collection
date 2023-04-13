// g++ string_class.cpp -o string_class && ./string_class

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

class String
{
public:
    // essential operations
    String();                       // default constructor : x{""}
    explicit String(const char *p); // constructor from C-style string: x{"Euler"}

    String(const String &);            // copy constr uctor
    String &operator=(const String &); // copy assignment
    // copy assignment from C-style string: x = "Euler"
    String &operator=(const char *);

    // by reference when dont need copy for copy be affordable
    String(String &&x);            // move constr uctor
    String &operator=(String &&x); // move assignment
    ~String()
    {
        if (short_max < sz)
            delete[] ptr;
    } // destructor

    // access to characters
    char &operator[](int n) { return ptr[n]; } // unchecked element access
    char operator[](int n) const { return ptr[n]; }
    // provide const and non-const versions of the access functions to allow them to be used for
    // const as well as other objects
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
    /*
    A simple string that implements the short string optimization

    size()==sz is the number of elements
    if size()<= short_max, the characters are held in the String object itself;
    otherwise the free store is used.

    ptr points to the start of the character sequence
    the character sequence is kept zero-terminated: ptr[size()]==0;
    this allows us to use C librar y string functions and to easily return a C-style string: c_str()

    To allow efficient addition of characters at end, String grows by doubling its allocation;
    capacity() is the amount of space available for characters
    (excluding the terminating 0): sz+space
    */
    static const int short_max = 15;
    int sz; // number of characters
    char *ptr;
    // anonymous union
    // , which is specifically designed to allow a class to manage alternative representations of
    // objects
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
    strcpy(p, ptr); // §43.4, copy elements from ptr to p
    return p;
}

void String::copy_from(const String &x)
// make *this a copy of x
{
    if (x.sz <= short_max)
    {                                // copy *this
        memcpy(this, &x, sizeof(x)); // §43.5
        // memcpy prototype: void *memcpy(void *dest, const void *src, size_t n);
        // copies n bytes from memory area src to memory area dest
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
    {                                // copy *this
        memcpy(this, &x, sizeof(x)); // §43.5
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

String::String()     // default constructor : x{""}
    : sz{0}, ptr{ch} // ptr points to elements, ch is an initial location (§19.3.3)
{
    ch[0] = 0; // terminating 0
}

String::String(const char *p)
    : sz{static_cast<int>(strlen(p))}, // number of characters
      ptr{(sz <= short_max) ? ch : new char[sz + 1]},
      space{0}
{
    strcpy(ptr, p); // copy characters into ptr from p
}

String::String(const String &x) // copy constr uctor
{
    copy_from(x); // copy representation from x
}

String::String(String &&x) // move constr uctor
{
    move_from(x);
}

String &String::operator=(const String &x)
{
    if (this == &x)
        return *this; // deal with self-assignment
    char *p = (short_max < sz) ? ptr : 0;
    copy_from(x);
    delete[] p;
    return *this;
}

String &String::operator=(const char *p)
{
    String x{p};
    *this = x;
    return *this;
}

String &String::operator=(String &&x)
{
    if (this == &x)
        return *this; // deal with self-assignment (x = move(x) is insanity)
    if (short_max < sz)
        delete[] ptr; // delete target
    move_from(x);     // does not throw
    return *this;
}

String &String::operator+=(char c)
{
    if (sz == short_max)
    {                        // expand to long string
        int n = sz + sz + 2; // double the allocation (+2 because of the terminating 0)
        ptr = expand(ptr, n);
        space = n - sz - 2;
    }
    else if (short_max < sz)
    {
        if (space == 0)
        {                        // expand in free store
            int n = sz + sz + 2; // double the allocation (+2 because of the terminating 0)
            char *p = expand(ptr, n);
            delete[] ptr;
            ptr = p;
            space = n - sz - 2;
        }
        else
            --space;
    }
    ptr[sz] = c;   // add c at end
    ptr[++sz] = 0; // increase size and set terminator
    return *this;
}

// stream
ostream &operator<<(ostream &os, const String &s)
{
    return os << s.c_str(); // §36.3.3
}

istream &operator>>(istream &is, String &s)
{
    s = String{""}; // clear the target string
    is >> ws;       // skip whitespace (§38.4.5.1)
    char ch = ' ';
    while (is.get(ch) && !isspace(ch))
        s += ch;
    return is;
}

// comparison
bool operator==(const String &a, const String &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i != a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}
bool operator!=(const String &a, const String &b)
{
    return !(a == b);
}
bool operator<(const String &a, const String &b)
{
    for (int i = 0; i != a.size() && i != b.size(); ++i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return a.size() < b.size();
}
bool operator>(const String &a, const String &b)
{
    return b < a;
}
bool operator<=(const String &a, const String &b)
{
    return !(b < a);
}
bool operator>=(const String &a, const String &b)
{
    return !(a < b);
}

// begin(), end()
char *begin(String &x) // C-string-style access
{
    const char *p = x.c_str();
    return const_cast<char *>(p); // cast away constness
}
char *end(String &x)
{
    return begin(x) + x.size();
}
const char *begin(const String &x)
{
    return x.c_str();
}
const char *end(const String &x)
{
    return x.c_str() + x.size();
}

// concatenation
String operator+=(String &a, const String &b)
{
    for (char c : b)
        a += c;
    return a;
}

String operator+(const String &a, const String &b) // concatenation
{
    String res{a};
    res += b;
    return res;
}

String operator+=(String &a, const char *p)
{
    return a += String{p};
}
String operator+(const String &a, const char *p)
{
    return a + String{p};
}

// string literal
String operator"" _s(const char *p, size_t) // user-defined literal
{
    return String{p};
}

// usage examples

// use [] for ordinary use
int calc_hash(const String &s)
{
    int h{s[0]};
    for (int i{1}; i != s.size(); i++)
        h ^= s[i] >> 1; // unchecked access to s
    return h;
}

//  use at() where we see a possibility of mistakes
void print_in_order(const String &s, const vector<int> &index)
{
    for (auto x : index)
        std::cout << s.at(x);
    std::cout << '\n';
}

int main(void)
{
    String s1{"Hello"};
    String s2{"World"};

    // [], at()
    int h1{calc_hash(s1)};
    print_in_order(s2, {1, 2, 0, 3});

    // +=
    std::cout << "length of s1: " << s1.size() << '\n';
    s1 += '!';
    std::cout << "length of s1 now: " << s1.size() << '\n';

    // += with reallocation
    for (int i{0}; i != 15; i++)
    {
        // add a digit
        s1 += i + '0';
        std::cout << "capacity: " << s1.capacity() << ", size: " << s1.size();
        std::cout << ", last char: " << s1[s1.size() - 1] << '\n';
    }

    // literal
    cout << "type of literal: " << typeid("Hello, World!"_s).name() << endl;

    // concate
    s1 += s2;
    std::cout << "s1: " << s1 << '\n';

    // more usages
    String s("abcdefghij");
    cout << s << '\n';
    s += 'k';
    s += 'l';
    s += 'm';
    s += 'n';
    cout << s << '\n';

    String s4 = "Hell"_s;
    s4 += " and high water";
    cout << s4 << '\n';
    String s5 = "qwerty"_s;
    s5 = s5;
    String s6 = "the quick bro wn fox jumped over the lazy dog"_s;
    s6 = s6;
    cout << s5 << " " << s6 << "\n";
    cout << s + ". " + s5 + String(". ") + "Horsefeathers\n";

    // input usage
    // String buf;
    // while (cin >> buf && buf != "quit"_s)
    //     cout << buf << " " << buf.size() << " " << buf.capacity() << '\n';

    return 0;
}