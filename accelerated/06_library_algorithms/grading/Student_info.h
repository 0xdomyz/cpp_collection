#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

// struct Student_info
// {
//     std::string name;
//     double midterm, final;
//     std::vector<double> homework;
// };

// instrumented version where we count
// the number of times the default constructor is called
// the number of times the copy constructor is called
// the number of times the assignment operator is called
// the number of times the destructor is called
struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;

    // counters
    static int default_ctor_calls;
    static int copy_ctor_calls;
    static int assign_calls;
    static int dtor_calls;

    Student_info() { ++default_ctor_calls; }
    Student_info(const Student_info &s)
        : name(s.name), midterm(s.midterm), final(s.final), homework(s.homework)
    {
        ++copy_ctor_calls;
    }
    Student_info &operator=(const Student_info &rhs)
    {
        ++assign_calls;
        name = rhs.name;
        midterm = rhs.midterm;
        final = rhs.final;
        homework = rhs.homework;
        return *this;
    }
    ~Student_info() { ++dtor_calls; }
};

bool compare(const Student_info &, const Student_info &);
std::istream &read(std::istream &, Student_info &);

#endif