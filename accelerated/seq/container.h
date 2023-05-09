#ifndef GUARD_container_h
#define GUARD_container_h

#include <vector>
#include <list>
#include <algorithm>

template <class T>
// using container = std::vector<T>;
using container = std::list<T>;

template <typename T>
void sortStudents(T &students)
{
    if constexpr (std::is_same_v<T, std::vector<Student_info>>)
    {
        std::sort(students.begin(), students.end(), compare);
    }
    else if constexpr (std::is_same_v<T, std::list<Student_info>>)
    {
        students.sort(compare);
    }
}

#endif