#include <iostream>
#include <vector>
#include <string>
#include "student_info.h"
#include <algorithm>
#include "grade.h"

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