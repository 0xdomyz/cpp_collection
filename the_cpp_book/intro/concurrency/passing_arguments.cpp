// Compile and run: g++ passing_arguments.cpp -lpthread -std=c++11 -o passing_arguments && ./passing_arguments

#include <iostream>
#include <thread>
#include <vector>
#include <pthread.h>

using namespace std;

void f(vector<double> &v)
{
    for (auto x : v)
    {
        cout << x << endl;
    }
}; // function do something with v

struct F
{ // function object: do something with v
    vector<double> &v;
    F(vector<double> &vv) : v{vv} {}
    void operator()()
    {
        for (auto x : v)
        {
            cout << x << endl;
        }
    }; // application operator ; §3.4.3
};

int main()
{
    vector<double> some_vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vec2{10, 11, 12, 13, 14};

    // execute f() in a separate thread
    thread t1{f, ref(some_vec)}; // f(some_vec) executes in a separate thread
    // ref is used to pass a reference to the vector
    // without ref, a copy of the vector is passed to the thread
    thread t2{F{ref(vec2)}}; // F(vec2)() executes in a separate thread
    t2.join();
    t1.join();
}
