// g++ -o test_Student_info test_Student_info.cpp Student_info.cpp && ./test_Student_info < extended.csv

#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"

using namespace std;

void test_basic()
{
    // Student_info s;
    // s.read(cin);
    Student_info s(cin);

    cout << s.valid() << endl;
    cout << s.grade() << endl;
}

void test_exception_trigger()
{
    Student_info s;
    s.grade();
    s.read(cin);
}

void test_exception_catch()
{
    Student_info s;
    try
    {
        s.grade();
    }
    catch (domain_error e)
    {
        s.read(cin);
        cout << s.grade() << endl;
    }
}

void test_check()
{
    Student_info s;
    if (s.valid())
        cout << s.grade() << endl;
    else
    {
        s.read(cin);
        cout << s.grade() << endl;
    }
}

void test_pass_fail_grade()
{
    Student_info s;
    s.read(cin);
    cout << s.pass_fail_grade() << endl;
}

void test_to_double()
{
    Student_info s;
    s.read(cin);
    cout << (double)s << endl;
}

void test_to_double2()
{
    vector<Student_info> vs;
    Student_info s;

    while (s.read(cin))
        if (s.valid())
            vs.push_back(s);

    double d = 0;
    for (int i = 0; i != vs.size(); ++i)
        d += vs[i]; // vs[i] is automatically converted to double
    cout << "The rest of the grades: " << endl;
    for (int i = 0; i != vs.size(); ++i)
        cout << vs[i].name() << ": " << vs[i] << endl;
    cout << "Average grades: " << d / vs.size() << endl;
}

int main(void)
{
    test_basic();
    // test_exception_trigger();
    test_exception_catch();
    test_check();
    test_pass_fail_grade();
    test_to_double();
    test_to_double2();
}