// compile and run: g++ -o derived_class derived_class.cpp && ./derived_class

#include <iostream>
#include <list>
#include <string>
#include <chrono>

using namespace std;

struct Employee
{
    string first_name, family_name;
    char middle_initial;
    short department;
    // a variable to sotr e higring date
    chrono::system_clock::time_point hire_date;
};

// {
//     Employee emp;          // manager’s employee record
//     list<Employee*> group; // people managed
//     short level;
//     // ...
// };

struct Manager : public Employee
{
    list<Employee *> group;
    short level;
    // ...
};

void f(Manager m1, Employee e1)
{
    list<Employee *> elist{&m1, &e1};
    // ...
}

void g(Manager mm, Employee ee)
{
    Employee *pe = &mm; // OK: every Manager is an Employee
    // Manager *pm = &ee;               // error : not every Employee is a Manager
    // pm->level = 2;                   // disaster : ee doesn’t have a lev el
    Manager *pm = static_cast<Manager *>(pe); // brute force: wor ks because pe points
    // to the Manager mm
    pm->level = 2; // fine: pm points to the Manager mm that has a level
}

int main(void)
{
    Manager m1;
    Employee e1;
    f(m1, e1);
    g(m1, e1);
    return 0;
}