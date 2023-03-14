#include <string>
#include <iostream>

using namespace std;

struct Entry
{
    string name;
    int number;
};

// prototype
ostream &operator<<(ostream &os, const Entry &e);

istream &operator>>(istream &is, Entry &e);
