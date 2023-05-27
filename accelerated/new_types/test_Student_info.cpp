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

void test_exception()
{
    Student_info s;
    s.grade();
    s.read(cin);
}

int main(void)
{
    // test_basic();
    test_exception();
}