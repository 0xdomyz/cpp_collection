#include <iostream>
#include <vector>
#include <string>
#include "student_info.h"
#include <algorithm>
#include "grade.h"
#include "letter_grade.h"

using namespace std;

string Core::name() const { return n; }

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream &Core::read_common(istream &in)
{
    // read and store the student's name and exam grades
    in >> n >> midterm >> final;
    return in;
}

// read homework grades from an input stream into a `vector'
istream &read_hw(istream &in, vector<double> &hw)
{
    if (in)
    {
        // get rid of previous contents
        hw.clear();
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream &Core::read(istream &in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

istream &Grad::read(istream &in)
{
    // read_common(in);
    Core::read_common(in);
    in >> Grad::thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(), thesis);
}

istream &Student_info::read(istream &is)
{
    delete cp; // delete previous object, if any
    char ch;
    is >> ch; // get record type
    if (ch == 'U')
    {
        cp = new Core(is);
    }
    else if (ch == 'P')
    {
        cp = new PassFail(is);
    }
    else if (ch == 'G')
    {
        cp = new Grad(is);
    }
    else if (ch == 'A')
    {
        cp = new Audit(is);
    }
    else
    {
        cp = 0;
        // throw runtime_error("read student info failed, first character is not U, P or G");
    }
    return is;
}

Student_info::Student_info(const Student_info &s) : cp(0)
{
    if (s.cp)
        cp = s.cp->clone();
}

Student_info &Student_info::operator=(const Student_info &s)
{
    if (&s != this)
    {
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
}

bool compare(const Core &c1, const Core &c2)
{
    return c1.name() < c2.name();
}

bool compare_by_grade(const Core &c1, const Core &c2)
{
    return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core *cp1, const Core *cp2)
{
    return compare(*cp1, *cp2);
}

std::string Core::letter_grade() const { return ::letter_grade(grade()); };

double PassFail::grade() const
{
    double score = (homework.empty()) ? (midterm + final) / 2 : Core::grade();
    return (score >= 60) ? 1 : 0;
}