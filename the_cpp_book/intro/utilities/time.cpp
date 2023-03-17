// Compile and run: g++ time.cpp -o time -lpthread && ./time

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono; // see §35.2
using namespace std;

void do_work(void)
{
    // sleep
    this_thread::sleep_for(chrono::seconds(2));
    // sleep for decimal seconds
    this_thread::sleep_for(chrono::milliseconds(505));
    // do something
    cout << "do_work" << endl;
}

int main(void)
{
    auto t0 = high_resolution_clock::now();
    do_work();
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1 - t0).count() << "msec\n";
}