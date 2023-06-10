#ifndef GUARD_PICTURES_H
#define GUARD_PICTURES_H

#include "Ptr.h"
#include <string>
#include <vector>

// private classes for use in the implementation only
class Pic_base
{
};

class String_Pic : public Pic_base
{
};
class Frame_Pic : public Pic_base
{
};
class VCat_Pic : public Pic_base
{
};
class HCat_Pic : public Pic_base
{
};

// public interface class and operations
class Picture
{
public:
    Picture(const std::vector<std::string> & =
                std::vector<std::string>());

private:
    Ptr<Pic_base> p;
};

// nonmember functions
Picture frame(const Picture &);
Picture hcat(const Picture &, const Picture &);
Picture vcat(const Picture &, const Picture &);

// overloaded output operator
std::ostream &operator<<(std::ostream &, const Picture &);

#endif