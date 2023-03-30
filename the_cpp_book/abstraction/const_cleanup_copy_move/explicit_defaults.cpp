// Compile and run: g++ explicit_defaults.cpp -o explicit_defaults && ./explicit_defaults

#include <string>
#include <valarray>

using namespace std;

class gslice
{
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> d1;

public:
    gslice() = default;
    ~gslice() = default;
    gslice(const gslice &) = default;
    gslice(gslice &&) = default;
    gslice &operator=(const gslice &) = default;
    gslice &operator=(gslice &&) = default;
    // ...
};

class gslice2
{
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> d1;

public:
    // ...
};

class gslice3
{
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> d1;

public:
    // ...
    gslice3(const gslice3 &a);
};
gslice3::gslice3(const gslice3 &a)
    : size{a.size},
      stride{a.stride},
      d1{a.d1}
{
}

int main(void)
{
    return 0;
}