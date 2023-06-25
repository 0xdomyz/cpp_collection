// g++ test2.cpp student_info.cpp -o test2 && ./test2 < test.csv

#include <iostream>
#include "student_info.h"

using namespace std;

int main(void)
{

    Core *p1_global;
    Core *p2_global;

    {
        cout << "calling Core *p1 = new Core;" << endl;
        Core *p1 = new Core;
        cout << endl;

        cout << "p1 usage" << endl;
        p1->read(cin);
        p1->grade();
        cout << p1->name() << endl;
        cout << endl;

        cout << "calling Core *p2 = new Grad;" << endl;
        Core *p2 = new Grad;
        cout << endl;

        cout << "p2 usage" << endl;
        p2->read(cin);
        p2->grade();
        cout << p2->name() << endl;
        cout << endl;

        cout << "assign to global pointers" << endl;
        p1_global = p1;
        p2_global = p2;

        cout << "end of scope" << endl;
    }

    cout << endl;

    {
        cout << "delete p1" << endl;
        delete p1_global;
        cout << "delete p2" << endl;
        delete p2_global;
        cout << endl;

        cout << "end of scope" << endl;
    }

    cout << endl;

    {
        cout << "calling Core s1;" << endl;
        Core s1;
        cout << endl;

        cout << "s1 usage" << endl;
        s1.read(cin);
        s1.grade();
        cout << s1.name() << endl;
        cout << endl;

        cout << "calling Grad s2;" << endl;
        Grad s2;
        cout << endl;

        cout << "s2 usage" << endl;
        s2.read(cin);
        s2.grade();
        cout << s2.name() << endl;
        cout << endl;

        cout << "end of scope" << endl;
    }
    cout << endl;
}