// compile and run:
// g++ -o grading analysis.cpp grading.cpp Student_info.cpp grade.cpp median.cpp seperate.cpp && ./grading < grades.csv

#include <iostream>
#include "grade.h"
#include "seperate.h"
#include "container.h"
#include <ctime>
#include "analysis.h"
#include "analysis.h"

using std::cin;
using std::clock;
using std::cout;
using std::sort;

// time start and finish of progrma to get running time

int main()
{
    // start timer
    clock_t start = clock();

    container<Student_info> did, didnt;
    Student_info student;
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student))
    {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
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

    return 0;
}
