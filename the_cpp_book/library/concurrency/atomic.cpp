// g++ atomic.cpp -o atomic -std=c++11 && ./atomic

#include <atomic>
#include <iostream>

using namespace std;

template <typename T>
class shared_ptr
{
public:
    // ..
    shared_ptr(T *p) : p(p), puc(new atomic<int>(1)) {}
    shared_ptr(const shared_ptr &sp) : p(sp.p), puc(sp.puc)
    {
        ++*puc;
    }
    shared_ptr &operator=(const shared_ptr &sp)
    {
        ++*sp.puc;
        if (--*puc == 0)
        {
            delete p;
            delete puc;
        }
        p = sp.p;
        puc = sp.puc;
        return *this;
    }
    // *p and p->m are equivalent
    T &operator*() const { return *p; }
    ~shared_ptr()
    {
        if (--*puc)
            delete p;
    }

private:
    T *p;             // pointer to shared object
    atomic<int> *puc; // pointer to use count
};

int main(void)
{
    shared_ptr<int> p(new int(42));
    shared_ptr<int> q(p);
    shared_ptr<int> r(p);
    cout << *p << endl;
    cout << *q << endl;
    cout << *r << endl;
    return 0;
}