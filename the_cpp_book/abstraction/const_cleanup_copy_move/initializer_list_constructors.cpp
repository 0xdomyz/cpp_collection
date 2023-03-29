// Compile and run: g++ initializer_list_constructors.cpp -o initializer_list_constructors && ./initializer_list_constructors

#include <iostream>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

vector<double> v = {1, 2, 3.456, 99.99};
list<pair<string, string>> languages = {
    {"Nygaard", "Simula"}, {"Richards", "BCPL"}, {"Ritchie", "C"}};
// map<vector<string>, vector<int>> years = {
vector<pair<vector<string>, vector<int>>> vec = {
    {{"Maurice", "Vincent", "Wilkes"}, {1913, 1945, 1951, 1967, 2000}},
    {{"Mar tin", "Richards"}, {1982, 2003, 2007}},
    {{"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004}}};
map<vector<string>, vector<int>> years(vec.begin(), vec.end());

void f(initializer_list<int> lst)
{
    for (auto p = lst.begin(); p != lst.end(); ++p)
        cout << *p << ' ';
    cout << endl;
}

struct X
{
    X(initializer_list<int>){};
    X(){};
    X(int){};
};

int main(void)
{
    void f(initializer_list<int>);
    f({1, 2});
    f({23, 345, 4567, 56789});
    f({}); // the empty list
    // f{1, 2}; // error : function call () missing
    years.insert({{"Bjarne", "Stroustrup"}, {1950, 1975, 1985}});

    X x0{};  // empty list: default constructor or initializer-list constructor? (the default constructor)
    X x1{1}; // one integer: an int argument or a list of one element? (the initializer-list constructor)

    vector<int> v1{1};       // one element
    vector<int> v2{1, 2};    // two elements
    vector<int> v3{1, 2, 3}; // three elements
    vector<string> vs1{"one"};
    vector<string> vs2{"one", "two"};
    vector<string> vs3{"one", "two", "three"};

    vector<int> vv1(1);    // one element with the default value (0)
    vector<int> vv2(1, 2); // one element with the value 2
}