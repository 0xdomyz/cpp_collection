#include "Student_info.h"
#include <algorithm>
#include "grade.h"
#include <stdexcept>
#include "median.h"
#include "analysis.h"
#include <numeric>
#include <vector>

using namespace std;

bool did_all_hw(const Student_info &s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info &s)
{
    try
    {
        return grade(s);
    }
    catch (domain_error)
    {
        return grade(s.midterm, s.final, 0);
    }
}

// median
// double median_analysis(const container<Student_info> &students)
// {
//     container<double> grades;
//     transform(students.begin(), students.end(),
//               back_inserter(grades), grade_aux);
//     return median(grades);
// }

// void write_analysis(ostream &out, const string &name,
//                     double analysis(const container<Student_info> &),
//                     const container<Student_info> &did,
//                     const container<Student_info> &didnt)

// defined as template, so no need to define it again

// double do_analysis(const container<Student_info> &students,
//                    double grade_func(const Student_info &))
// {
//     container<double> grades;
//     transform(students.begin(), students.end(),
//               back_inserter(grades), grade_func);
//     return median(grades);
// }

// void write_analysis(ostream &out, const string &name,
//                     double grade_func(const Student_info &),
//                     const container<Student_info> &did,
//                     const container<Student_info> &didnt)
// {
//     out << name;
//     out << ": median(did) = " << do_analysis(did, grade_func);
//     out << ", median(didnt) = " << do_analysis(didnt, grade_func);
//     out << endl;
// }

// avg
double average(const vector<double> &v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info &s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

// double average_analysis(const container<Student_info> &students)
// {
//     container<double> grades;
//     transform(students.begin(), students.end(),
//               back_inserter(grades), average_grade);
//     return median(grades);
// }

// opt
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info &s)
{
    container<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

// double optimistic_median_analysis(const container<Student_info> &students)
// {
//     container<double> grades;
//     transform(students.begin(), students.end(),
//               back_inserter(grades), optimistic_median);
//     return median(grades);
// }
