#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <vector>
#include <string>

class Core
{
public:
    Core() : midterm(0), final(0) {}
    Core(std::istream &in) { read(in); }
    std::string name() const;
    virtual std::istream &read(std::istream &);
    virtual double grade() const;

protected:
    std::istream &read_common(std::istream &);
    double midterm, final;
    std::vector<double> homework;

private:
    std::string n;
};

class Grad : public Core
{
public:
    Grad() : thesis(0) {}
    Grad(std::istream &in) { read(in); }
    double grade() const;
    std::istream &read(std::istream &);

private:
    double thesis;
};

bool compare(const Core &c1, const Core &c2);

bool compare_by_grade(const Core &c1, const Core &c2);

#endif