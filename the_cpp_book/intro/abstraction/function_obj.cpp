// g++ -o function_obj function_obj.cpp && ./function_obj

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class Less_than
{
    const T val; // value to compare against
public:
    Less_than(const T &v) : val(v) {}
    bool operator()(const T &x) const { return x < val; } // call operator
};

void fct(int n, const string &s)
{
    Less_than<int> lti{42};          // lti(i) will compare i to 42 using < (i<42)
    Less_than<string> lts{"Backus"}; // lts(s) will compare s to "Backus" using < (s<"Backus")

    bool b1 = lti(n); // true if n<42
    bool b2 = lts(s); // true if s<"Backus"
    // ...

    cout << b1 << b2 << endl;
}

// use functor as a function template argument
template <typename C, typename P>
int count(const C &c, P pred)
{
    int cnt = 0;
    for (const auto &x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

// predicate for finding a value in a container
void f(const vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x
         << ": " << count(vec, Less_than<int>{x})
         << '\n';
    cout << "number of values less than " << s
         << ": " << count(lst, Less_than<string>{s})
         << '\n';
}

// lambda
void f2(const vector<int> &vec, const list<string> &lst, int x, const string &s)
{
    cout << "number of values less than " << x
         << ": " << count(vec, [&](int a)
                          { return a < x; })
         << '\n';
    cout << "number of values less than " << s
         << ": " << count(lst, [&](const string &a)
                          { return a < s; })
         << '\n';
}

// seperate traversal and action
template <class C, class Oper>
void for_all(C &c, Oper op) // assume that C is a container of pointers
{
    for (auto &x : c)
        op(*x); // pass op() a reference to each element pointed to
}

void user()
{
    cout << "user" << endl;
    vector<char *> v;
    v.push_back(new char('a'));
    v.push_back(new char('b'));
    for_all(v, [](char &s)
            { cout << sizeof(s) << endl; });
    for_all(v, [](char &s)
            { cout << s << endl; });
}

int main(void)
{
    fct(1, "hello");
    f({1, 2, 3, 4, 5, 6, 7, 8, 9}, {"hello", "world"}, 5, "hello");
    f2({1, 2, 3, 4, 5, 6, 7, 8, 9}, {"hello", "world"}, 5, "hello");
    user();
    return 0;
}