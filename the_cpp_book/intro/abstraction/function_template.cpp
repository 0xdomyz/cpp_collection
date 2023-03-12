// g++ -o function_template function_template.cpp && ./function_template

#include <iostream>
#include <vector>
#include <list>
#include <complex>

using namespace std;

template <typename Container, typename Value>
Value sum(const Container &c, Value v)
{
    for (auto x : c)
        v += x;
    return v;
}

void user(vector<int> &vi, std::list<double> &ld, std::vector<complex<double>> &vc)
{
    int x = sum(vi, 0);                  // the sum of a vector of ints (add ints)
    double d = sum(vi, 0.0);             // the sum of a vector of ints (add doubles)
    double dd = sum(ld, 0.0);            // the sum of a list of doubles
    auto z = sum(vc, complex<double>{}); // the sum of a vector of complex<double>
    // the initial value is {0.0,0.0}

    cout << x << " " << d << " " << dd << " " << z << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    list<double> l = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector<complex<double>> c = {{1, 2}, {3, 4}, {5, 6}};

    user(v, l, c);
}