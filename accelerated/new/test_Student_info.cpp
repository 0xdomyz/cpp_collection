// g++ -o test_Student_info test_Student_info.cpp Student_info.cpp && ./test_Student_info < basic.csv

#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"

using namespace std;

int main(void)
{
    Student_info s;
    s.read(cin);
    cout << s.grade() << endl;
}