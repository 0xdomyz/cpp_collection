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
    Core() : midterm(0), final(0)
    {
        std::cerr << "Core::Core()" << std::endl;
    }
    Core(std::istream &in)
    {
        std::cerr << "Core::Core(std::istream &in)" << std::endl;
        read(in);
    }
    virtual ~Core()
    {
        std::cerr << "Core::~Core()" << std::endl;
    }
    Core(const Core &c) : midterm(c.midterm), final(c.final), homework(c.homework), n(c.n)
    {
        std::cerr << "Core::Core(const Core &c)" << std::endl;
    };
    Core &operator=(const Core &c)
    {
        std::cerr << "Core::operator=(const Core &c)" << std::endl;
        midterm = c.midterm;
        final = c.final;
        homework = c.homework;
        n = c.n;
        return *this;
    }
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
    Grad() : thesis(0)
    {
        std::cerr << "Grad::Grad()" << std::endl;
    }
    Grad(std::istream &in)
    {
        std::cerr << "Grad::Grad(std::istream &in)" << std::endl;
        read(in);
    }
    ~Grad()
    {
        std::cerr << "Grad::~Grad()" << std::endl;
    }
    double grade() const;
    std::istream &read(std::istream &);

protected:
    virtual Grad *clone() const { return new Grad(*this); }

private:
    double thesis;
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