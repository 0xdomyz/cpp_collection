#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Core
{
    friend class Student_info;

public:
    Core() : midterm(0), final(0) {}
    Core(std::istream &in) { read(in); }
    virtual ~Core() {}
    std::string name() const;
    virtual std::istream &read(std::istream &);
    virtual double grade() const;
    std::string letter_grade() const;
    virtual bool valid() const { return !homework.empty(); }

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
    bool valid() const { return !homework.empty() && thesis != 0; }

protected:
    virtual Grad *clone() const { return new Grad(*this); }

private:
    double thesis;
};

class PassFail : public Core
{
public:
    PassFail() : Core() {}
    PassFail(std::istream &in) { read(in); }
    double grade() const;
    bool valid() const { return 1; }

protected:
    virtual PassFail *clone() const { return new PassFail(*this); }
};

class Audit : public Core
{
public:
    Audit() : Core() {}
    Audit(std::istream &in) { read(in); }
    double grade() const { return 0; };
    bool valid() const { return 1; }

protected:
    virtual Audit *clone() const { return new Audit(*this); }
};

class Student_info
{
public:
    // constructors and copy control
    Student_info() : cp(0) {}
    Student_info(std::istream &is) : cp(0) { read(is); }
    Student_info(const Student_info &);
    Student_info &operator=(const Student_info &);
    ~Student_info() { delete cp; }
    // operations
    std::istream &read(std::istream &);
    std::string name() const
    {
        if (cp)
            return cp->name();
        else
            throw std::runtime_error("uninitialized Student");
    }
    double grade() const
    {
        if (cp)
            return cp->grade();
        else
            throw std::runtime_error("uninitialized Student");
    }
    bool initialized() const { return cp; }
    bool valid() const
    {
        if (cp)
            return cp->valid();
        else
            throw std::runtime_error("uninitialized Student");
    }
    std::string letter_grade() const
    {
        if (cp)
            return cp->letter_grade();
        else
            throw std::runtime_error("uninitialized Student");
    }
    static bool compare(const Student_info &s1,
                        const Student_info &s2)
    {
        return s1.name() < s2.name();
    }

private:
    Core *cp;
};

bool compare(const Core &c1, const Core &c2);

bool compare_by_grade(const Core &c1, const Core &c2);

bool compare_Core_ptrs(const Core *cp1, const Core *cp2);

#endif