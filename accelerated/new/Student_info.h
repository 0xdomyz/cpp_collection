#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>
#include <iostream>

struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    std::istream &read(std::istream &); // added
    double grade() const;               // added
};

bool compare(const Student_info &x, const Student_info &y);

#endif