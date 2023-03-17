// Compile and run: g++ packaged_task.cpp -lpthread -o packaged_task && ./packaged_task

#include <vector>
#include <thread>
#include <algorithm>
#include <iostream>
#include <future>
#include <numeric>

using namespace std;

double accum(double *beg, double *end, double init)
// compute the sum of [beg:end) starting with the initial value init
{
    return accumulate(beg, end, init);
}
double comp2(vector<double> &v)
{
    using Task_type = double(double *, double *, double); // type of task
    packaged_task<Task_type> pt0{accum};                  // package the task (i.e., accum)
    packaged_task<Task_type> pt1{accum};
    future<double> f0{pt0.get_future()}; // get hold of pt0’s future
    future<double> f1{pt1.get_future()}; // get hold of pt1’s future
    double *first = &v[0];
    thread t1{move(pt0), first, first + v.size() / 2, 0};            // star t a thread for pt0
    thread t2{move(pt1), first + v.size() / 2, first + v.size(), 0}; // star t a thread for pt1
    // ...
    t1.join();
    t2.join();
    return f0.get() + f1.get(); // get the results
}

int main(void)
{
    vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    double res = comp2(v);
    cout << res << endl;
    return 0;
}