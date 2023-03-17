// Compile and run: g++ async.cpp -o async -lpthread && ./async

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

using namespace std;

double accum(double *beg, double *end, double init)
// compute the sum of [beg:end) starting with the initial value init
{
    return accumulate(beg, end, init);
}

double comp4(vector<double> &v)
// spawn many tasks if v is large enough
{
    if (v.size() < 10000)
        return accumulate(v.begin(), v.end(), 0.0);

    cout << "slow path" << endl;
    auto v0 = &v[0];
    auto sz = v.size();
    auto f0 = async(accum, v0, v0 + sz / 4, 0.0);              // first quarter
    auto f1 = async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);     // second quarter
    auto f2 = async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0); // third quarter
    auto f3 = async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0);     // four th quar ter
    return f0.get() + f1.get() + f2.get() + f3.get();          // collect and combine the results
}

int main(void)
{
    vector<double> v(10001, 3.14);
    double res = comp4(v);
    cout << res << endl;

    // make big vector
    vector<double> v2(100000000, 3.14);
    double res2 = comp4(v2);
    cout << res2 << endl;
    return 0;
}