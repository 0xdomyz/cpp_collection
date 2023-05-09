// compile and run:
// g++ -o grading grading.cpp Student_info.cpp grade.cpp median.cpp seperate.cpp && ./grading < grades.txt

// test file: ./make_test_file 1000 test_file.csv && ./grading < test_file.csv
// ./make_test_file 1000 test_1000.csv
// ./make_test_file 10000 test_10000.csv
// ./make_test_file 20000 test_20000.csv
// ./make_test_file 50000 test_50000.csv
// ./make_test_file 100000 test_100000.csv
// ./make_test_file 500000 test_500000.csv

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

using std::cin;
using std::cout;
using std::sort;

int main()
{
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
    auto fails = extract_fails(students);

    // write the names and grades of not fails
    cout << "Passing students:\n";
    write_names_and_grade(students);

    // write the names and grades of the fails
    cout << "\nFailing students:\n";
    write_names_and_grade(fails);

    return 0;
}
