// g++ si_grading.cpp students_Ptr.cpp -o si_grading && ./si_grading < mix.csv

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "student_info_ptr.h"

using namespace std;

bool operator<(const Student_info &x, const Student_info &y)
{
    return x.name() < y.name();
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin))
    {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    // compare must be rewritten to work on const Student_info&
    sort(students.begin(), students.end());

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try
        {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << endl;
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
        }
    }
    return 0;
}
