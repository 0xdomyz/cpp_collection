// wip
// g++ string_template.cpp -o string_template
// make list of words: echo "aaa bbb aaa" > words.txt
// ./string_template < words.txt

#include <iostream>
#include <map>

using namespace std;

template <typename C>
class String
{
public:
    String();
    explicit String(const C *);
    String(const String &);
    String operator=(const String &);
    // ...
    C &operator[](int n) { return ptr[n]; } // unchecked element access
    String &operator+=(C c);                // add c at end
    // ...
    int size() const { return sz; };
    // less than, greater than, etc.
private:
    static const int short_max = 15; // for the short str ing optimization
    int sz;
    C *ptr; // ptr points to sz Cs
};

template <typename C>
String<C>::String() : sz{0}, ptr{nullptr}
{
}

template <typename C>
String<C>::String(const C *p) : sz{0}, ptr{p}
{
    while (sz < short_max && (*ptr++ = *p++))
        ++sz;
    if (sz == short_max)
        while (*p++)
            ++sz;
    *ptr = 0;
}

template <typename C>
String<C>::String(const String &s) : sz{s.sz}, ptr{s.ptr}
{
    if (sz > short_max)
    {
        ptr = new C[sz + 1];
    }
    for (int i = 0; i <= sz; ++i)
        ptr[i] = s.ptr[i];
}

template <typename C>
String<C> String<C>::operator=(const String &s)
{
    if (this == &s)
        return *this;
    if (sz > short_max)
        delete[] ptr;
    sz = s.sz;
    if (sz > short_max)
        ptr = new C[sz + 1];
    for (int i = 0; i <= sz; ++i)
        ptr[i] = s.ptr[i];
    return *this;
}

template <typename C>
String<C> &String<C>::operator+=(C c)
{
    if (sz == short_max)
    {
        C *p = new C[sz * 2 + 2];
        for (int i = 0; i < sz; ++i)
            p[i] = ptr[i];
        ptr = p;
    }
    else if (sz > short_max)
    {
        C *p = new C[sz + 2];
        for (int i = 0; i < sz; ++i)
            p[i] = ptr[i];
        delete[] ptr;
        ptr = p;
    }
    ptr[sz] = c;
    ptr[++sz] = 0;
    return *this;
}

template <typename C>
ostream &operator<<(ostream &os, const String<C> &s)
{
    return os << s.ptr;
}

template <typename C>
istream &operator>>(istream &is, String<C> &s)
{
    s = String<C>();
    C c;
    while (is.get(c) && isspace(c))
        ;
    if (is)
    {
        do
            s += c;
        while (is.get(c) && !isspace(c));
        if (is)
            is.unget();
    }
    return is;
}

template <typename C>
bool operator==(String<C> &a, String<C> &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

template <typename C>
bool operator!=(String<C> &a, String<C> &b)
{
    return !(a == b);
}

template <typename C>
bool operator<(String<C> &a, String<C> &b)
{
    for (int i = 0; i != a.size() && i != b.size(); ++i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return a.size() < b.size();
}

template <typename C>
bool operator>(String<C> &a, String<C> &b)
{
    return b < a;
}

template <typename C>
bool operator<=(String<C> &a, String<C> &b)
{
    return !(b < a);
}

// String<char> cs;
// String<unsigned char> us;
// String<wchar_t> ws;
// struct Jchar
// {  /* ... */
// }; // Japanese character
// String<Jchar> js;

int main() // count the occurrences of each word on input
{
    map<String<char>, int> m;
    for (String<char> buf; cin >> buf;)
        ++m[buf];
    // ... write out result ...
    // for (auto &x : m)
    //     cout << x.first << ": " << x.second << '\n';
}

// int main() // count the occurrences of each word on input
// {
//     map<String<Jchar>, int> m;
//     for (String<Jchar> buf; cin >> buf;)
//         ++m[buf];
//     // ... write out result ...
// }

// int main() // count the occurrences of each word on input
// {
//     map<string, int> m;
//     for (string buf; cin >> buf;)
//         ++m[buf];
//     // ... write out result ...
// }