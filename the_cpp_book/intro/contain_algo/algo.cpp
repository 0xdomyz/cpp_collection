// Compile object file: g++ -c entry.cpp
// Compile: g++ algo.cpp entry.o -o algo
// run: ./algo

// above in 1 line: g++ algo.cpp entry.cpp -o algo && ./algo

#include "entry.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

bool operator<(const Entry &x, const Entry &y) // less than
{
    return x.name < y.name; // order Entrys by their names
}

bool operator==(const Entry &x, const Entry &y) // equal
{
    return x.name == y.name;
}

void f(vector<Entry> &vec, list<Entry> &lst)
{
    sort(vec.begin(), vec.end());                     // use < for order
    unique_copy(vec.begin(), vec.end(), lst.begin()); // don’t copy adjacent equal elements
}

list<Entry> f2(vector<Entry> &vec)
{
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res)); // append to res
    return res;
}

int main()
{
    // basic
    std::vector<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}};

    for (const auto &x : phone_book)
        std::cout << x << std::endl;

    // sort
    sort(phone_book.begin(), phone_book.end());

    cout << "sorted:" << endl;
    for (const auto &x : phone_book)
        std::cout << x << std::endl;

    // unique_copy
    list<Entry> lst(3);
    f(phone_book, lst);

    cout << "lst:" << endl;
    for (const auto &x : lst)
        std::cout << x << std::endl;

    // unique_copy with back_inserter
    list<Entry> lst2 = f2(phone_book);

    cout << "lst2:" << endl;
    for (const auto &x : lst2)
        std::cout << x << std::endl;

    return 0;
}