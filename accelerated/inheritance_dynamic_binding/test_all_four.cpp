// g++ test_all_four.cpp student_info.cpp -o test_all_four && ./test_all_four < test_all_four.csv

#include <iostream>
#include "student_info.h"
#include <cassert>

using namespace std;

int main(void)
{

    Student_info record;

    while (record.read(cin))
    {
        cout << record.name() << " " << record.grade() << endl;
    }
}