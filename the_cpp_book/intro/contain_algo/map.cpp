// Compile and run: g++ map.cpp -o map && ./map

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

map<string, int> phone_book{
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Ber trand Ar thur William Russell", 345678}};

int get_number(const string &s)
{
    return phone_book[s];
}

unordered_map<string, int> phone_book2{
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Ar thur William Russell", 345678}};

int get_number2(const string &s)
{
    return phone_book2[s];
}

int main()
{
    cout << get_number("David Hume") << '\n';
    cout << get_number("Karl Popper") << '\n';
    cout << get_number("Bertrand Ar thur William Russell") << '\n';

    cout << get_number2("David Hume") << '\n';
    cout << get_number2("Karl Popper") << '\n';
    cout << get_number2("Bertrand Ar thur William Russell") << '\n';
}