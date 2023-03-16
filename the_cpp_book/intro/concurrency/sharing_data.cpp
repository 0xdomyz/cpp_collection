// Compile and run: g++ -lpthread sharing_data.cpp -o sharing_data && ./sharing_data

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m; // controlling mutex
int sh;  // shared data
void f()
{
    unique_lock<mutex> lck{m}; // acquire mutex
    sh += 7;                   // manipulate shared data
} // release mutex implicitly

class Record
{
public:
    mutex rm;
    // ...
    int id = 0;
};

void f2(Record &r)
{
    unique_lock<mutex> lck{r.rm}; // acquire mutex
    r.id += 7;                    // manipulate shared data
} // release mutex implicitly

mutex m1, m2, m3;  // controlling mutexes
int sh1, sh2, sh3; // shared data

void f3()
{
    // ...
    unique_lock<mutex> lck1{m1, defer_lock}; // defer_lock: don’t yet try to acquire the mutex
    unique_lock<mutex> lck2{m2, defer_lock};
    unique_lock<mutex> lck3{m3, defer_lock};
    // ...
    lock(lck1, lck2, lck3); // acquire all three locks
    // ... manipulate shared data ...
    sh1 += 7;
    sh2 += 7;
    sh3 += 7;

} // implicitly release all mutexes

int main(void)
{
    cout << sh << " " << sh1 << " " << sh2 << " " << sh3 << endl;
    f();

    f3();
    cout << sh << " " << sh1 << " " << sh2 << " " << sh3 << endl;

    Record r;
    cout << r.id << endl;
    f2(r);
    cout << r.id << endl;
}
