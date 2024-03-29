// g++ -std=c++11 slice.cpp -o slice && ./slice

#include <iostream>

struct slice
//  A slice describes a subset of the elements of a dimension (§40.5.4).
// In particular, slice{i,n} refers to elements [i:i+n) of the
// dimension to which it applies
//
// Selecting all elements from a point onward is so common that there is a shorthand:
// slice{i} means
// slice{i,max} where max is larger than the largest subscript in the dimension.
{
    slice() : start(-1), length(-1), stride(1) {}
    explicit slice(size_t s) : start(s), length(-1), stride(1) {}
    slice(size_t s, size_t l, size_t n = 1) : start(s), length(l), stride(n) {}

    size_t operator()(size_t i) const { return start + i * stride; }
    static slice all;
    size_t start;  // first index
    size_t length; // number of indices included (can be used for range checking)
    size_t stride; // distance between elements in sequence
    friend std::ostream &operator<<(std::ostream &os, const slice &s)
    {
        return os << "slice(" << s.start << ", " << s.length << ", " << s.stride << ")";
    }
};

int main(void)
{
    slice s0;
    std::cout << "default" << s0 << std::endl;

    slice s1{3};
    std::cout << "s1(3)" << s1 << std::endl;

    slice s2{1, 3};
    std::cout << "s2(1, 3)" << s2 << std::endl;

    slice s3{1, 3, 1};
    std::cout << "s3(1, 3, 1)" << s3 << std::endl;

    slice s4{1, 3, 2};
    std::cout << "s4(1, 3, 2)" << s4 << std::endl;
    std::cout << s4(0) << std::endl;
    std::cout << s4(1) << std::endl;
    std::cout << s4(2) << std::endl;
    std::cout << s4(3) << std::endl;

    return 0;
}