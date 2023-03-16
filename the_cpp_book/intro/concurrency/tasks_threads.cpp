// Compile and run: g++ tasks_threads.cpp -o tasks_threads -lpthread && ./tasks_threads

#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;

void f() { cout << "Hello "; }
struct F
{
    void operator()() { cout << "Parallel World!\n"; }
};
void user()
{
    thread t1{f};   // f() executes in separate thread
    thread t2{F()}; // F()() executes in separate thread
    t1.join();      // wait for t1
    t2.join();      // wait for t2
}

int main(void)
{
    user();
    return 0;
}