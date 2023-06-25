// g++ test_letter_grade.cpp student_info.cpp -o test_letter_grade && ./test_letter_grade < test_letter_grade.csv

#include <iostream>
#include "student_info.h"
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    Student_info s;

    s.read(cin);
    cout << s.name() << " " << s.grade() << " " << s.letter_grade() << endl;

    s.read(cin);
    cout << s.name() << " " << s.grade() << " " << s.letter_grade() << endl;

    return 0;
}