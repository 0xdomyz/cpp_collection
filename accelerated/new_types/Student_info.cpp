#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "letter_grade.h"
#include "Student_info.h"

using namespace std;

Student_info::Student_info() : midterm(0), final(0), g(0){};

double grade(double midterm, double final, const vector<double> &hw);

Student_info::Student_info(istream &is)
{
    read(is);
};

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

istream &Student_info::read(istream &in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);

    // pre-calculate grade
    // if (valid())
    //     g = ::grade(midterm, final, homework);
    // else
    //     g = 0;

    return in;
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info &x, const Student_info &y)
{
    return x.name() < y.name();
};

// bool compare(Student_info &x, Student_info &y)
// {
//     return x.name() < y.name();
// };

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double> &hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

// double Student_info::grade() const // if pre-calculate
// {
//     return g;
// }
double Student_info::grade() const // if not pre-calculate
{
    return ::grade(midterm, final, homework);
}

string pass_fail_grade(double midterm, double final)
{
    double avg = 0.5 * midterm + 0.5 * final;
    if (avg >= 60)
        return string("P");
    else
        return string("F");
}

string Student_info::pass_fail_grade() const
{
    return ::pass_fail_grade(midterm, final);
}

string Student_info::letter_grade() const
{
    return ::letter_grade(grade());
}
