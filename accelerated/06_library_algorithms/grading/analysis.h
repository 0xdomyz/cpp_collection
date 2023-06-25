#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include "Student_info.h"
#include "container.h"
#include <string>
#include "median.h"

bool did_all_hw(const Student_info &s);

// double median_analysis(const container<Student_info> &students);

// double average_analysis(const container<Student_info> &students);

// double optimistic_median_analysis(const container<Student_info> &students);

// void write_analysis(std::ostream &out, const std::string &name,
//                     double analysis(const container<Student_info> &),
//                     const container<Student_info> &did,
//                     const container<Student_info> &didnt);

double grade_aux(const Student_info &s);
double average_grade(const Student_info &s);
double optimistic_median(const Student_info &s);

// void write_analysis(std::ostream &out, const std::string &name,
//                     double grade_func(const Student_info &),
//                     const container<Student_info> &did,
//                     const container<Student_info> &didnt);

// use templates

template <class Function>
double do_analysis(const container<Student_info> &students, Function grade_func)
{
    container<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), grade_func);
    return median(grades);
}

template <class Function>
void write_analysis(std::ostream &out, const std::string &name,
                    Function grade_func,
                    const container<Student_info> &did,
                    const container<Student_info> &didnt)
{
    out << name;
    out << ": median(did) = " << do_analysis(did, grade_func);
    out << ", median(didnt) = " << do_analysis(didnt, grade_func);
    out << std::endl;
}

#endif