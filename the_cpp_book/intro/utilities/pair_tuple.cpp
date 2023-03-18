// Compile and run: g++ pair_tuple.cpp -o pair_tuple && ./pair_tuple

#include <utility>
#include <tuple>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Record
{
public:
    string name;
    int age;
    double salary;
};

// define operator<< for Record
void operator<<(ostream &os, const Record &r)
{
    os << r.name << ' ' << r.age << ' ' << r.salary << '\n';
}

// template <typename Forward_iterator, typename T, typename Compare>
// pair<Forward_iterator, Forward_iterator>
// equal_range(Forward_iterator first, Forward_iterator last, const T &val, Compare cmp);

auto rec_eq = [](const Record &r1, const Record &r2)
{ return r1.name < r2.name; }; // compare names

void f(const vector<Record> &v) // assume that v is sorted on its "name" field
{
    auto er = equal_range(v.begin(), v.end(), Record{"Reg"}, rec_eq);
    for (auto p = er.first; p != er.second; ++p) // print all equal records
        cout << *p;                              // assume that << is defined for Record
}

void f(vector<string> &v)
{
    auto pp = make_pair(v.begin(), 2); // pp is a pair<vector<str ing>::iterator,int>
    // all equal elements
    auto er = equal_range(v.begin(), v.end(), "Reg");
    for (auto p = er.first; p != er.second; ++p) // print all equal elements
        cout << *p << '\n';
}

int main(void)
{

    tuple<string, int, double> t2("Sild", 123, 3.14); // the type is explicitly specified
    auto t = make_tuple(string("Herring"), 10, 1.23); // the type is deduced
    // t is a tuple<str ing,int,double>

    string s = get<0>(t); // get first element of tuple
    int x = get<1>(t);
    double d = get<2>(t);

    cout << s << ' ' << x << ' ' << d << '\n';

    vector<Record> vr;
    vr.push_back(Record{"Reg", 10, 1.23});
    vr.push_back(Record{"Reg1", 204, 2.34});
    vr.push_back(Record{"Reg", 10, 1.23});
    vr.push_back(Record{"Reg", 0, 0});

    f(vr);

    vector<string> vs;
    vs.push_back("Reg");
    vs.push_back("Reg1");
    vs.push_back("Reg");

    f(vs);

    return 0;
}
