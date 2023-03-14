// Compile and run: g++ vector.cpp -o vector && ./vector

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// set up
struct Entry
{
    string name;
    int number;
};

ostream &operator<<(ostream &os, const Entry &e)
{
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream &operator>>(istream &is, Entry &e)
// read { "name" , number } pair. Note: for matted with { " " , and }
{
    char c, c2;
    if (is >> c && c == '{' && is >> c2 && c2 == '"')
    {                                 // star t with a { "
        string name;                  // the default value of a string is the empty string: ""
        while (is.get(c) && c != '"') // anything before a " is part of the name
            name += c;
        if (is >> c && c == ',')
        {
            int number = 0;
            if (is >> number >> c && c == '}')
            {                       // read the number and a }
                e = {name, number}; // assign to the entry
                return is;
            }
        }
    }
    is.setstate(ios_base::failbit);

    return is;
}

// start

vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Ar thur William Russell", 345678}};

void print_book(const vector<Entry> &book)
{
    for (int i = 0; i != book.size(); ++i)
        cout << book[i] << '\n';
}

void print_book2(const vector<Entry> &book)
{
    for (const auto &x : book) // for "auto" see §2.2.2
        cout << x << '\n';
}

vector<int> v1 = {1, 2, 3, 4}; // size is 4
vector<string> v2;             // size is 0
vector<Entry *> v3(23);        // size is 23; initial element value: nullptr
vector<double> v4(32, 9.9);    // size is 32; initial element value: 9.9

void input()
{
    for (Entry e; cin >> e;)
        phone_book.push_back(e);
}

void silly(vector<Entry> &book)
{
    int i = book[book.size()].number; // book.size() is out of range
    // ...
}

template <typename T>
class Vec : public std::vector<T>
{
public:
    using vector<T>::vector; // use the constructors from vector (under the name Vec); see §20.3.5.1
    T &operator[](int i)     // range check
    {
        return vector<T>::at(i);
    }
    const T &operator[](int i) const // range check const objects; §3.2.1.1
    {
        return vector<T>::at(i);
    }
};

void checked(Vec<Entry> &book)
{
    try
    {
        book[book.size()] = {"Joe", 999999}; // will throw an exception
        // ...
    }
    catch (out_of_range)
    {
        cout << "range error\n";
    }
}

int main()
try
{
    print_book(phone_book);
    print_book2(phone_book);
    input();
    print_book(phone_book);

    cout << "start checked" << endl;
    Vec<Entry> book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Ar thur William Russell", 345678}};
    checked(book);
    cout << "end checked" << endl;

    silly(phone_book);
    return 0;
}
catch (out_of_range)
{
    cerr << "main range error\n";
}
catch (...)
{
    cerr << "unknown exception thrown\n";
}