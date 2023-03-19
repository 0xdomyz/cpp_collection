// g++ struct.cpp -o struct && ./struct

#include <iostream>

using namespace std;

struct Address
{
    const char *name;   // "Jim Dandy"
    int number;         // 61
    const char *street; // "South St"
    const char *town;   // "New Providence"
    char state[2];      // 'N' 'J'
    const char *zip;    // "07974"
};

void f()
{
    Address jd;
    jd.name = "Jim Dandy";
    jd.number = 61;
}

void print_addr(Address *p)
{
    cout << p->name << '\n'
         << p->number << ' ' << p->street << '\n'
         << p->town << '\n'
         << p->state[0] << p->state[1] << ' ' << p->zip << '\n';
    cout << "\n";
}

void print_addr2(const Address &r)
{
    cout << r.name << '\n'
         << r.number << ' ' << r.street << '\n'
         << r.town << '\n'
         << r.state[0] << r.state[1] << ' ' << r.zip << '\n';
    cout << "\n";
}

Address current;
Address set_current(Address next)
{
    Address prev = current;
    current = next;
    return prev;
}

int main(void)
{
    f();

    Address jd = {
        "Jim Dandy",
        61,
        "South St",
        "New Providence",
        {'N', 'J'},
        "07974"};
    print_addr(&jd);
    print_addr2(jd);

    current = jd;
    Address next = {
        "Tom Thumb",
        33,
        "North St",
        "New Providence",
        {'N', 'J'},
        "07974"};
    Address prev = set_current(next);
    cout << "current:\n";
    print_addr(&current);
}