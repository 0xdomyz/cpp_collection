// g++ -std=c++17 -o class class.cpp && ./class

#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(int s) : elem{new double[s]}, sz{s} {} // constr uct a Vector
    double &operator[](int i) { return elem[i]; } // element access: subscripting
    int size() { return sz; }

private:
    double *elem; // pointer to the elements
    int sz;       // the number of elements
};

double read_and_sum(int s)
{
    Vector v(s); // make a vector of s elements
    for (int i = 0; i != v.size(); ++i)
        cin >> v[i]; // read into elements
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
        sum += v[i]; // take the sum of the elements
    return sum;
}

int main()
{
    cout << "Enter the number of values you want to sum: ";
    int s;
    cin >> s;
    cout << "Enter some numbers (press '|' to stop): ";
    // | is the end of file character
    // it is used to stop the input
    double sum = read_and_sum(s);
    cout << "Sum of " << s << " numbers: " << sum << endl;
}