#ifndef GUARD_seperate_h
#define GUARD_seperate_h

#include "Student_info.h"
#include <vector>

// separate passing and failing student records: first try
std::vector<Student_info> extract_fails(std::vector<Student_info> &students);

#endif