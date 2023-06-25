#include <iostream>
#include <vector>
#include <string>
#include "student_info.h"
#include <algorithm>
#include "grade.h"

using namespace std;

string Core::name() const
{
    cout << "Core::name() const" << endl;
    return n;
}

double Core::grade() const
{
    return ::grade(midterm, final, homework);
}

istream &Core::read_common(istream &in)
{
    cout << "Core::read_common(istream &in)" << endl;
    // read and store the student's name and exam grades
    in >> n >> midterm >> final;
    return in;
}

// read homework grades from an input stream into a `vector'
istream &read_hw(istream &in, vector<double> &hw)
{
    cout << "read_hw(istream &in, vector<double> &hw)" << endl;
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
    cout << "Core::read(istream &in)" << endl;
    read_common(in);
    read_hw(in, homework);
    return in;
}

istream &Grad::read(istream &in)
{
    cout << "Grad::read(istream &in)" << endl;
    // read_common(in);
    Core::read_common(in);
    cout << "Grad read thesis" << endl;
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
    else
    {
        cp = new Grad(is);
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
