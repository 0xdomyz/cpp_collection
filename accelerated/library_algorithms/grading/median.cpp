// source file for the median function
#include <algorithm> // to get the declaration of sort
#include <stdexcept> // to get the declaration of domain_error
#include <vector>    // to get the declaration of vector
#include "median.h"
#include <list>

using namespace std;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
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

double median(list<double> vec)
{
    typedef list<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty list");
    vec.sort();

    vector<double> vec2;
    copy(vec.begin(), vec.end(), back_inserter(vec2));

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec2[mid] + vec2[mid - 1]) / 2 : vec2[mid];
}