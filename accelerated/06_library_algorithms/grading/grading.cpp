// compile and run:
// g++ -o grading analysis.cpp grading.cpp Student_info.cpp grade.cpp median.cpp seperate.cpp && ./grading < grades.csv

#include <iostream>
#include "grade.h"
#include "seperate.h"
#include "container.h"
#include <ctime>
#include "analysis.h"
#include <algorithm>

using std::cin;
using std::clock;
using std::cout;
using std::sort;

// initialize counters
int Student_info::default_ctor_calls = 0;
int Student_info::copy_ctor_calls = 0;
int Student_info::assign_calls = 0;
int Student_info::dtor_calls = 0;

// time start and finish of progrma to get running time

int main()
{
    // start timer
    clock_t start = clock();

    container<Student_info> did, didnt;
    Student_info student;
    // read all the records, separating them based on whether all homework was done
    // while (read(cin, student))
    // {
    //     if (did_all_hw(student))
    //         did.push_back(student);
    //     else
    //         didnt.push_back(student);
    // }

    // read into one container
    container<Student_info> students;
    while (read(cin, student))
    {
        students.push_back(student);
    }

    // stable partition
    auto it = stable_partition(students.begin(), students.end(), did_all_hw);
    copy(students.begin(), it, back_inserter(did));
    copy(it, students.end(), back_inserter(didnt));

    // check that both groups contain data
    if (did.empty())
    {
        cout << "No student did all the homework!" << std::endl;
        return 1;
    }
    if (didnt.empty())
    {
        cout << "Every student did all the homework!" << std::endl;
        return 1;
    }

    cout << "did.size(): " << did.size() << std::endl;
    cout << "didnt.size(): " << didnt.size() << std::endl;

    // do the analyses
    // write_analysis(cout, "median", median_analysis, did, didnt);
    // write_analysis(cout, "average", average_analysis, did, didnt);
    // write_analysis(cout, "median of homework turned in",
    //                optimistic_median_analysis, did, didnt);
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in",
                   optimistic_median, did, didnt);

    // stop timer
    clock_t finish = clock();
    cout << "Running time: " << (double)(finish - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // type of container is
    cout << "type of container is: " << typeid(did).name() << std::endl;

    // print counters
    cout << "default_ctor_calls: " << Student_info::default_ctor_calls << std::endl;
    cout << "copy_ctor_calls: " << Student_info::copy_ctor_calls << std::endl;
    cout << "assign_calls: " << Student_info::assign_calls << std::endl;
    cout << "dtor_calls: " << Student_info::dtor_calls << std::endl;

    return 0;
}
