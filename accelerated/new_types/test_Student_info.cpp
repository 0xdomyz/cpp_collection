// g++ -o test_Student_info test_Student_info.cpp Student_info.cpp && ./test_Student_info < basic.csv

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

int main(void)
{
    // test_basic();
    // test_exception_trigger();
    // test_exception_catch();
    // test_check();
    test_pass_fail_grade();
}