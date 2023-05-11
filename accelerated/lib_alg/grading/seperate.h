#ifndef GUARD_seperate_h
#define GUARD_seperate_h

#include "Student_info.h"
#include "container.h"

// separate passing and failing student records
container<Student_info> extract_fails(container<Student_info> &students);

#endif