#ifndef GUARD_PICTURES_H
#define GUARD_PICTURES_H

#include "Ptr.h"
#include <string>
#include <vector>

class Picture;

// private classes for use in the implementation only
class Pic_base
{
    friend std::ostream &operator<<(std::ostream &,
                                    const Picture &);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    // no public interface
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream &, ht_sz, bool) const = 0;
};

class String_Pic : public Pic_base
{
    friend class Picture;

    std::vector<std::string> data;
    String_Pic(const std::vector<std::string> &v) : data(v) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream &, ht_sz, bool) const;
};

class Frame_Pic : public Pic_base
{
    friend Picture frame(const Picture &);

    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base> &pic) : p(pic) {}

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream &, ht_sz, bool) const;
};

class VCat_Pic : public Pic_base
{
    friend Picture vcat(const Picture &, const Picture &);

    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base> &t, const Ptr<Pic_base> &b) : top(t), bottom(b) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream &, ht_sz, bool) const;
};

class HCat_Pic : public Pic_base
{
    friend Picture hcat(const Picture &, const Picture &);

    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base> &l, const Ptr<Pic_base> &r) : left(l), right(r) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream &, ht_sz, bool) const;
};

// public interface class and operations
class Picture
{
    friend Picture frame(const Picture &);
    friend Picture hcat(const Picture &, const Picture &);
    friend Picture vcat(const Picture &, const Picture &);
    friend std::ostream &operator<<(std::ostream &, const Picture &);

public:
    Picture(const std::vector<std::string> & =
                std::vector<std::string>());
    Picture(Pic_base *ptr) : p(ptr){};

private:
    Ptr<Pic_base> p;
};

// nonmember functions
Picture frame(const Picture &pic);
Picture hcat(const Picture &, const Picture &);
Picture vcat(const Picture &, const Picture &);

// overloaded output operator
std::ostream &operator<<(std::ostream &, const Picture &);

#endif