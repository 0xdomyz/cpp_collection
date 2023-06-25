// compile and run:
// g++ -o grading grading.cpp Student_info.cpp grade.cpp median.cpp seperate.cpp && ./grading < grades.txt

// tests
// ./grading < test_1000.csv
// ./grading < test_10000.csv
// ./grading < test_20000.csv
// ./grading < test_50000.csv
// ./grading < test_100000.csv
// ./grading < test_500000.csv

#include <iostream>
#include "grade.h"
#include "seperate.h"
#include "container.h"
#include <ctime>

using std::cin;
using std::clock;
using std::cout;
using std::sort;

// time start and finish of progrma to get running time

int main()
{
    // start timer
    clock_t start = clock();

    container<Student_info> students;

    // read and store all the students data.
    Student_info record;
    while (read(cin, record))
    {
        students.push_back(record);
    }

    // alphabetize the student records
    sortStudents(students);

    // extract the fails
    auto fails = extract_fails(students, fgrade);

    // write the names and grades of not fails
    cout << "Passing students:\n";
    write_names_and_grade(students);

    // write the names and grades of the fails
    cout << "\nFailing students:\n";
    write_names_and_grade(fails);

    // stop timer
    clock_t finish = clock();
    cout << "Running time: " << (double)(finish - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}
