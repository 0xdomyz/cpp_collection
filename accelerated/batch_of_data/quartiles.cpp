// g++ -std=c++11 quartiles.cpp -o quartiles && ./quartiles

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // read into a vector
    cout << "Please enter a set of numbers: ";
    vector<double> set;
    double x;
    while (cin >> x)
    {
        set.push_back(x);
    }

    // check if the set is empty
    auto size = set.size();
    if (size == 0)
    {
        cout << "No numbers entered. Please try again." << endl;
        return 1;
    }

    // sort the set
    sort(set.begin(), set.end());

    // calculate the quartiles via vector indexing
    double q1 = size % 4 == 0 ? (set[size / 4] + set[size / 4 - 1]) / 2 : set[size / 4];
    double q2 = size % 2 == 0 ? (set[size / 2] + set[size / 2 - 1]) / 2 : set[size / 2];
    double q3 = size % 4 == 0 ? (set[size * 3 / 4] + set[size * 3 / 4 - 1]) / 2 : set[size * 3 / 4];

    // print the quartiles
    cout << "The quartiles of the set are: " << endl;
    cout << "Q1: " << q1 << endl;
    cout << "Q2: " << q2 << endl;
    cout << "Q3: " << q3 << endl;

    return 0;
}
