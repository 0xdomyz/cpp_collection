// g++ test_passfail.cpp student_info.cpp -o test_passfail && ./test_passfail < test_passfail.csv

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