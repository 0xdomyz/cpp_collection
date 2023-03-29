// Compile and run: g++ member_initialization.cpp -o member_initialization && ./member_initialization

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
    int y, m, d;
    Date(int y, int m, int d);
};

class Club
{
    string name;
    vector<string> members;
    vector<string> officers;
    Date founded;
    // ...
public:
    Club(const string &n, Date fd);
    Club(const string &n, Date fd, vector<string> m, vector<string> o);
};

Club::Club(const string &n, Date fd, vector<string> m, vector<string> o)
    : name{n}, members{m}, officers{o}, founded{fd}
{
    // ...
}

Club::Club(const string &n, Date fd)
    : name{n}, founded{fd}
{
    // ...
}

struct B
{
    B(int){}; /* ... */
};
struct BB : B
{ /* ... */
};
struct BBB : BB
{
    // BBB(int i) : B(i){}; // error : tr ying to initialize base’s base
    // ...
};

// assignment
class X
{
    const int i;
    Club cl;
    Club &rc;
    // ...
    X(int ii, const string &n, Date d, Club &c) : i{ii}, cl{n, d}, rc{c} {}
};

class Person
{
    string name;
    string address;
    // ...
    Person(const Person &);
    Person(const string &n, const string &a);
};
Person::Person(const string &n, const string &a)
    : name{n}
{
    address = a;
}

int main(void)
{
    return 0;
}