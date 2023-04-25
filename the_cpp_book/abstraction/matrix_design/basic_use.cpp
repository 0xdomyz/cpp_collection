// g++ basic_use.cpp -o basic_use && ./basic_use

#include "matrix.h"

using namespace matrix;

int main(void)
{
    // usage
    Matrix<double, 0> m0{1};          // zero dimensions: a scalar
    Matrix<double, 1> m1{1, 2, 3, 4}; // one dimension: a vector (4 elements)
    Matrix<double, 2> m2{
        // two dimensions (4*3 elements)
        {00, 01, 02, 03}, // row 0
        {10, 11, 12, 13}, // row 1
        {20, 21, 22, 23}  // row 2
    };
    Matrix<double, 3> m3(4, 7, 9);   // three dimensions (4*7*9 elements), all 0-initialized
    Matrix<complex<double>, 17> m17; // 17 dimensions (no elements so far)

    // element type
    Matrix<double, 2> md;        // OK
    Matrix<string, 2> ms;        // OK: just don’t try arithmetic operations
    Matrix<Matrix<int, 2>, 2> mm{// 3-by-2 matrix of 2-by-2 matrices
                                 // a matr ix is a plausible "number"
                                 {
                                     // row 0
                                     {{1, 2}, {3, 4}}, // col 0
                                     {{4, 5}, {6, 7}}, // col 1
                                 },
                                 {
                                     // row 1
                                     {{8, 9}, {0, 1}}, // col 0
                                     {{2, 3}, {4, 5}}, // col 1
                                 },
                                 {
                                     // row 2
                                     {{1, 2}, {3, 4}}, // col 0
                                     {{4, 5}, {6, 7}}, // col 1
                                 }};

    // specify size and elements
    Matrix<char, 2> mc1(2, 3, 4); // error : too many dimension sizes
    Matrix<char, 2> mc2{
        {'1', '2', '3'} // error : initializer missing for second dimension
    };
    Matrix<char, 2> mc2{
        {'1', '2', '3'},
        {'4', '5'} // error : element missing for third column
    };

    // order, extent, and size
    Matrix<double, 1> m1(100);      // one dimension: a vector (100 elements)
    Matrix<double, 2> m2(50, 6000); // two dimensions: 50*6000 elements
    auto d1 = m1.order();           // 1
    auto d2 = m2.order();           // 2
    auto e1 = m1.extent(0);         // 100
    auto e1 = m1.extent(1);         // error : m1 is one-dimensional
    auto e2 = m2.extent(0);         // 50
    auto e2 = m2.extent(1);         // 6000
    auto s1 = m1.size();            // 100
    auto s2 = m2.size();            // 50*6000

    // subscripting
    Matrix<double, 2> m{
        // two dimensions (4*3 elements)
        {00, 01, 02, 03}, // row 0
        {10, 11, 12, 13}, // row 1
        {20, 21, 22, 23}  // row 2
    };
    double d1 = m(1, 2);         // d==12
    double d2 = m[1][2];         // d==12
    Matrix<double, 1> m1 = m[1]; // row 1: {10,11,12,13}
    double d3 = m1[2];           // d==12

    // output func for debugging
    // out<<m prints: {{0,1,2,3},{10,11,12,13},{20,21,22,23}}.
    template <typename M>
    Enable_if<Matrix_type<M>(), ostream &>
    operator<<(ostream &os, const M &m)
    {
        os << '{';
        for (siz e_t i = 0; i != rows(m); ++i)
        {
            os << m[i];
            if (i + 1 != rows(m))
                os << ',';
        }
        return os << '}';
    }

    return 0;
}