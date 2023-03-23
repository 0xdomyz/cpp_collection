// g++ thread.cpp -o thread -lpthread -std=c++11 && ./thread

#include <thread>
#include <iostream>

using namespace std;

void f(void)
{
    // id The type of a thread identifier
    // native_handle_type The type of a system’s thread handle; implementation-defined (§iso.30.2.3)
    // thread t {}; Default constructor: create a thread that does not (yet) have a task; noexcept
    // thread t {t2}; Move constructor; noexcept
    // thread t {f,args}; Constructor: execute f(args) on a new thread; explicit
    // t.˜thread(); Destructor: if t.joinable(), then terminate(); otherwise no effect
    // t=move(t2) Move assignment: if t.joinable(), then terminate(); noexcept
    // t.swap(t2) Exchange the values of t and t2; noexcept
    // t.joinable() Is there a thread of execution associated with t?
    // t.get_id()!=id{}?; noexcept
    // t.join() Join t with the current thread; that is, block the current thread until t completes; throw system_error if a deadlock is detected (e.g., t.get_id()==this_thread::get_id()); throw system_error if t.id==id{}
    // t.detach() Ensure that no system thread is represented by t; throw system_error if t.id!=id{}
    // x=t.get_id() x is the id of t; noexcept
    // x=t.native_handle() x is the native handle for t (of native_handle_type)
    // n=hardware_concurrency() n is the number of hardware processing units (0 means ‘‘don’t know’’); noexcept
    // swap(t,t2) t.swap(t2); noexcept

    thread t1{[]
              { cout << "Hello from thread 1" << endl; }};
    thread t2{[]
              { cout << "Hello from thread 2" << endl; }};

    // move t1 to t3
    thread t3{move(t1)};

    // swap t2 and t3
    t2.swap(t3);

    // joinable() returns true if the thread is joinable
    if (t1.joinable())
        t1.join();

    // get id
    cout << "t2 id: " << t2.get_id() << endl;

    // detach
    t3.detach(); // t3 is no longer joinable

    // get id
    cout << "t3 id: " << t3.get_id() << endl;

    thread t4{[]
              { cout << "Hello from thread 4" << endl; }};

    // join
    t2.join();
    t4.join();
}

int main(void)
{
    f();
    return 0;
}