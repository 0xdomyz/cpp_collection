#ifndef GUARD_students_h
#define GUARD_students_h

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Ptr.h"

class Core
{
    friend class Ptr<Core>;

public:
    Core() : midterm(0), final(0) {}
    Core(std::istream &in) { read(in); }
    virtual ~Core() {}
    std::string name() const;
    virtual std::istream &read(std::istream &);
    virtual double grade() const;

protected:
    std::istream &read_common(std::istream &);
    double midterm, final;
    std::vector<double> homework;
    virtual Core *clone() const { return new Core(*this); }

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

protected:
    virtual Grad *clone() const { return new Grad(*this); }

private:
    double thesis;
};

bool compare(const Core &c1, const Core &c2);

bool compare_by_grade(const Core &c1, const Core &c2);

bool compare_Core_ptrs(const Core *cp1, const Core *cp2);

#endif