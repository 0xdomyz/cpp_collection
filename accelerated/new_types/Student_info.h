#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info
{
public:
    Student_info();
    Student_info(std::istream &);

    std::istream &read(std::istream &);
    double grade() const;
    std::string pass_fail_grade() const;
    std::string letter_grade() const;
    std::string name() const { return n; };
    // std::string name() { return n; };
    bool valid() const { return !homework.empty(); };

    operator double() { return grade(); };
    operator double() const { return grade(); };

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
    double g;
};

bool compare(const Student_info &x, const Student_info &y);
// bool compare(Student_info &x, Student_info &y);

#endif
