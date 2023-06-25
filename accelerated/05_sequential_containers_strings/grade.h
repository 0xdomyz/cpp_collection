#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include "Student_info.h"
#include "container.h"

double grade(const Student_info &);

void write_names_and_grade(const container<Student_info> &students);

#endif