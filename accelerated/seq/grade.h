#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);

void write_names_and_grade(const std::vector<Student_info> &students);

#endif