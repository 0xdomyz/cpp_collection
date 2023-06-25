// g++ test.cpp student_info.cpp -o test && ./test < test.csv

#include <iostream>
#include "student_info.h"

using namespace std;

int main(void)
{
    {
        Student_info s;

        cout << "calling read(cin) on s" << endl;
        s.read(cin);
        cout << s.name() << s.grade() << endl;

        // copy cons and assign op on handle
        cout << "calling Student_info s2(s)" << endl;
        Student_info s2(s);

        cout << "calling s2 = s" << endl;
        s2 = s;

        cout << "end of scope" << endl;
    }

    cout << endl;

    {
        Student_info s;

        cout << "calling read(cin) on s" << endl;
        s.read(cin);
        cout << s.name() << s.grade() << endl;

        // copy cons and assign op on handle
        cout << "calling Student_info s2(s)" << endl;
        Student_info s2(s);

        cout << "calling s2 = s" << endl;
        s2 = s;

        cout << "end of scope" << endl;
    }

    cout << endl;
}