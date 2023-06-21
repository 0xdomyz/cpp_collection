// g++ test.cpp student_info.cpp -o test && ./test < test.csv

#include <iostream>
#include "student_info.h"

using namespace std;

int main(void)
{
    {
        Student_info s;

        s.read(cin);
        cout << s.name() << s.grade() << endl;

        s.read(cin);
        cout << s.name() << s.grade() << endl;
    }
}