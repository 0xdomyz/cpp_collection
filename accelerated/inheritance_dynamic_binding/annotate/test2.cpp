// g++ test2.cpp student_info.cpp -o test2 && ./test2 < test.csv

#include <iostream>
#include "student_info.h"

using namespace std;

int main(void)
{

    {
        cout << "calling Core *p1 = new Core;" << endl;
        Core *p1 = new Core;
        cout << endl;

        cout << "calling Core *p2 = new Grad;" << endl;
        Core *p2 = new Grad;
        cout << endl;

        cout << "calling Core s1;" << endl;
        Core s1;
        cout << endl;

        cout << "calling Grad s2;" << endl;
        Grad s2;
        cout << endl;

        cout << "p1 usage" << endl;
        p1->read(cin);
        p1->grade();
        cout << p1->name() << endl;
    }

    {
    }
}