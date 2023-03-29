// Compile and run: g++ direct_and_copy_initialization.cpp -o direct_and_copy_initialization && ./direct_and_copy_initialization

#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> vs = {
    {10, 11, 12, 13, 14}, // OK: vector of five elements
    {10},                 // OK: vector of one element
    // 10,                             // error : vector<double>(int) is explicit
    vector<double>{10, 11, 12, 13}, // OK: vector of five elements
    vector<double>{10},             // OK: vector of one element with value 10.0
    vector<double>(10),             // OK: vector of 10 elements with value 0.0
};

vector<double> v1(7); // OK: v1 has 7 elements; note: uses () rather than {}
// vector<double> v2 = 9; // error : no conversion from int to vector
void f(const vector<double> &){};
void g()
{
    // v1 = 9; // error : no conversion from int to vector
    // f(9);   // error : no conversion from int to vector
}

void g2()
{
    vector<double> v1{7};    // OK: v1 has one element (with the value 7)
    vector<double> v2 = {9}; // OK: v2 has one element (with the value 9)
    v1 = {9};                // OK: v1 now has one element (with the value 9)
    f({9});                  // OK: f is called with the list {9}
}

void h(void)
{
    vector<double> v1{7, 8, 9};    // OK: v1 has three elements with values {7,8,9}
    vector<double> v2 = {9, 8, 7}; // OK: v2 has three elements with values {9,8,7}
}

void g3()
{
    v1 = {9, 10, 11};      // OK: v1 now has three elements with values {9,10,11}
    f({9, 8, 7, 6, 5, 4}); // OK: f is called with the list {9,8,7,6,5,4}
}

void f3(const vector<string> &){};
void g4()
{
    vector<string> v1{"Anya"};        // OK: v1 has one element (with the value "Anya")
    vector<string> v2 = {"Courtney"}; // OK: v2 has one element (with the value "Courtney")
    v1 = {"Gavin"};                   // OK: v1 now has one element (with the value "Gavin")
    f3({"Norah"});                    // OK: f is called with the list {"Norah"}
}

int main(void)
{
    return 0;
}