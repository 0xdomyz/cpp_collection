// usual setup: compile cmd, include io, vector, using namespace std
// g++ -o grading grading.cpp Student_info.cpp && ./grading < extended.csv
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "Student_info.h"
#include <iomanip>

using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    // read and store the data
    while (record.read(cin))
    {                                               // changed
        maxlen = max(maxlen, record.name().size()); // changed
        students.push_back(record);
    }
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        cout << students[i].name() // changed
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try
        {
            double final_grade = students[i].grade(); // changed
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
