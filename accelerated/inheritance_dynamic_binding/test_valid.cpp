// g++ test_valid.cpp student_info.cpp -o test_valid && ./test_valid < test_valid.csv

#include <iostream>
#include "student_info.h"
#include <cassert>

using namespace std;

int main(void)
{

    {
        Student_info record;

        // test initialization and read
        assert(!record.initialized());
        record.read(cin);
        assert(record.initialized());

        cout << record.name() << endl;

        if (record.valid())
        {
            cout << record.grade() << endl;
        }
        else
        {
            cout << "Invalid student record" << endl;
        }

        // second set of tests
        record.read(cin);
        cout << record.name() << endl;
        if (record.valid())
        {
            cout << record.grade() << endl;
        }
        else
        {
            cout << "Invalid student record" << endl;
        }

        // third set of tests
        record.read(cin);
        cout << record.name() << endl;
        if (record.valid())
        {
            cout << record.grade() << endl;
        }
        else
        {
            cout << "Invalid student record" << endl;
        }
    }
}