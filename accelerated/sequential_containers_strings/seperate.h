#ifndef GUARD_seperate_h
#define GUARD_seperate_h

#include "Student_info.h"
#include "container.h"

// separate passing and failing student records
// container<Student_info> extract_fails(container<Student_info> &students);

container<Student_info> extract_fails(container<Student_info> &students, bool criteria(const Student_info &));

bool fgrade(const Student_info &s);
bool pgrade(const Student_info &s);

#endif