// Compile and run: g++ -lpthread waiting_for_time.cpp -o waiting_for_time && ./waiting_for_time

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono; // see §35.2

int main(void)
{
  auto t0 = high_resolution_clock::now();
  this_thread::sleep_for(milliseconds{20});
  auto t1 = high_resolution_clock::now();
  cout << duration_cast<nanoseconds>(t1 - t0).count() << " nanoseconds passed\n";
}