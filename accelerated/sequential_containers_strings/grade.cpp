#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double> &hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info &s)
{
    return grade(s.midterm, s.final, s.homework);
}

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include "container.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setprecision;
using std::streamsize;
using std::string;

void write_names_and_grade(const container<Student_info> &students)
{
    // find max length of name
    string::size_type maxlen = 0;
    for (auto iter = students.begin();
         iter != students.end(); ++iter)
        maxlen = max(maxlen, iter->name.size());

    auto size = students.size();
    const auto max_size = 10;
    if (size > max_size)
    {
        cout << "size: " << size << endl;
        cout << "only printing first " << max_size << " students" << endl;
        size = max_size;
    }

    // write the names and grades
    auto i = 0;
    for (auto p_student = students.begin(); i < size; ++p_student, ++i)
    {
        Student_info student = *p_student;
        // write the name, padded on the right to maxlen + 1 characters
        cout << student.name
             << string(maxlen + 1 - student.name.size(), ' ');
        // compute and write the grade
        try
        {
            double final_grade = grade(student);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
}
