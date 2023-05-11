#include "seperate.h"
#include "grade.h"
#include "Student_info.h"
#include "container.h"
#include <iostream>

using namespace std;

// predicate to determine whether a student failed
bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

// separate passing and failing student records: first try, require 2 copies of students
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> pass, fail;
//     for (vector<Student_info>::size_type i = 0;
//          i != students.size(); ++i)
//         if (fgrade(students[i]))
//             fail.push_back(students[i]);
//         else
//             pass.push_back(students[i]);
//     students = pass;
//     return fail;
// }

// second try: correct but potentially slow
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail;
//     vector<Student_info>::size_type i = 0;
//     while (i != students.size())// invariant:elements [0, i) of students represent passing grades
//     {
//         if (fgrade(students[i]))
//         {
//             fail.push_back(students[i]);
//             students.erase(students.begin() + i);
//         }
//         else
//         {
//             ++i;
//         }
//     }
//     return fail;
// }

// version 3: iterators but no indexing; still potentially slow
// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     vector<Student_info> fail;
//     vector<Student_info>::iterator iter = students.begin();
//     while (iter != students.end())
//     {
//         if (fgrade(*iter))
//         {
//             fail.push_back(*iter);
//             iter = students.erase(iter);
//         }
//         else
//             ++iter;
//     }
//     return fail;
// }

// version 4: use list instead of vector
// #include <list>

// list<Student_info> extract_fails(list<Student_info> &students)
// {
//     list<Student_info> fail;
//     list<Student_info>::iterator iter = students.begin();
//     while (iter != students.end())
//     {
//         if (fgrade(*iter))
//         {
//             fail.push_back(*iter);
//             iter = students.erase(iter);
//         }
//         else
//             ++iter;
//     }
//     return fail;
// }

// vector<Student_info> extract_fails(vector<Student_info> &students)
// {
//     // vector to list
//     list<Student_info> students_list(students.begin(), students.end());
//     // call list version
//     list<Student_info> fail_list = extract_fails(students_list);
//     // list to vector
//     vector<Student_info> fail(fail_list.begin(), fail_list.end());
//     // list to vector
//     students.assign(students_list.begin(), students_list.end());
//     return fail;
// }

// version 5, use container

container<Student_info> extract_fails(container<Student_info> &students)
{
    container<Student_info> fail;
    container<Student_info>::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

// version 6, only work with list
// container<Student_info> extract_fails(container<Student_info> &students)
// {
//     auto size = students.size();

//     container<Student_info> fail;
//     for (auto i = 0; i != students.size(); ++i)
//     {
//         if (fgrade(students[i]))
//         {
//             fail.push_back(students[i]);
//         }
//         else
//         {
//             students.insert(students.begin(), students[i]);
//             i++;
//         }
//     }

//     students.resize(students.size() - size);

//     return fail;
// }
