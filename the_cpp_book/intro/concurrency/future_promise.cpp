// Compile and run: g++ future_promise.cpp -o future_promise -lpthread && ./future_promise

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>

using namespace std;

class X
{
public:
    string s;
    int i;
    X() : s("default"), i(0) {}
    X(string s, int i) : s(s), i(i) {}
};

void f(promise<X> &px) // a task: place the result in px
{
    // ...
    try
    {
        X res;
        // ... compute a value for res ...
        res.s = "result";
        px.set_value(res);
    }
    catch (...)
    { // oops: couldn’t compute res
        // pass the exception to the future’s thread:
        px.set_exception(current_exception());
    }
}

void g(future<X> &fx) // a task: get the result from fx
{
    // ...
    try
    {
        X v = fx.get(); // if necessary, wait for the value to get computed
        // ... use v ...
        cout << v.s << endl;
    }
    catch (...)
    { // oops: someone couldn’t compute v
        // ... handle error ...
        throw;
    }
}

int main()
{
    promise<X> px;                  // create a promise
    future<X> fx = px.get_future(); // get a future
    thread t1{f, ref(px)};          // start a task using px
    thread t2{g, ref(fx)};          // start a task using fx
    t1.join();
    t2.join();
}
