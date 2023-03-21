// g++ time.cpp -o time && ./time

#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace std;

void f()
{
    auto t = steady_clock::now();
    // ... do something ...
    auto d = steady_clock::now() - t;                                            // something took d time units
    cout << "something took " << duration_cast<milliseconds>(d).count() << "ms"; // print as milliseconds
    cout << endl;
}

int main(void)
{
    steady_clock::time_point t = steady_clock::now();
    // ... do something ...
    for (int i = 0; i < 100000000; i++)
        ;
    steady_clock::duration d = steady_clock::now() - t;                          // something took d time units
    cout << "something took " << duration_cast<milliseconds>(d).count() << "ms"; // print as milliseconds
    cout << endl;

    f();
}