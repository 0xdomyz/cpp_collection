// Compile and run: g++ waiting_for_events.cpp -o waiting_for_events -lpthread && ./waiting_for_events

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>

using namespace std;

class Message
{ // object to be communicated
  // ...
public:
    int id;
    string text;
};
queue<Message> mqueue;    // the queue of messages
condition_variable mcond; // the var iable communicating events
mutex mmutex;             // the locking mechanism

// predicate to check if the queue is not empty, as lambda expression
auto queue_not_empty = []()
{ return !mqueue.empty(); };

void consumer()
{
    while (true)
    {
        unique_lock<mutex> lck{mmutex};   // acquire mmutex
        mcond.wait(lck, queue_not_empty); // wait for notification
        cout << "acquired" << endl;
        // re-acquire lck upon wakeup
        auto m = mqueue.front(); // get the message
        mqueue.pop();
        // ... process m ...
        cout << "message received" << endl;
        m.text = "processed";
        lck.unlock(); // release lck
        // cout << "end of consumer" << endl;
    }
}

void producer()
{
    while (true)
    {
        // cout << "start of producer" << endl;
        Message m;
        // ... fill the message ...
        unique_lock<mutex> lck{mmutex}; // protect operations
        mqueue.push(m);
        cout << "message sent" << endl;
        // sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));
        mcond.notify_one(); // notify
        // release lock
        lck.unlock();
        cout << "unlocked" << endl;
    } // release lock (at end of scope)
}

int main(void)
{
    thread t1{consumer};
    thread t2{producer};
    t1.join();
    t2.join();
}