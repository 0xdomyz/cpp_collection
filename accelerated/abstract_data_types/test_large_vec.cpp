// g++ test_large_vec.cpp -o test_large_vec && ./test_large_vec

#include <iostream>
#include <chrono>
#include "vec.h"

using namespace std;

long time_from_last_call()
{
    static auto last = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(now - last);
    long res = duration.count();
    last = now;
    return res;
}

int main(void)
{
    time_from_last_call();
    Vec<int> v;
    for (int i = 0; i < 10000; ++i)
        v.push_back(i);
    cout << "time takes: " << time_from_last_call() << " microseconds" << endl;
}