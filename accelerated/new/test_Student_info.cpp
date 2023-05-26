// g++ -o test_Student_info test_Student_info.cpp Student_info.cpp && ./test_Student_info < basic.csv

#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"

using namespace std;

int main(void)
{
    // Student_info s;
    // s.read(cin);
    Student_info s(cin);

    cout << s.valid() << endl;
    cout << s.grade() << endl;
}