// Compile and run: g++ user_io.cpp -o user_io && ./user_io

#include <iostream>
#include <string>

using namespace std;

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
    // register the failure in the stream
    is.setstate(ios_base::failbit);
    // return the stream so that it can be used in an expression
    // setstate() vs setf():
    // setstate() sets the state of the stream to the value of the argument.
    // setf() sets the state of the stream to the value of the argument
    // and also sets the format flags to the value of the argument.
    // in this case, we don't want to set the format flags.

    return is;
}

int main(void)
{
    // Entry e;
    // cin >> e;
    // cout << e << endl;

    for (Entry ee; cin >> ee;) // read from cin into ee
        cout << ee << '\n';    // write ee to cout
}