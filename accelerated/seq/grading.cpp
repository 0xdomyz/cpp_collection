// compile and run: g++ -o grading grading.cpp Student_info.cpp grade.cpp median.cpp seperate.cpp && ./grading < grades.txt
// test file: ./make_test_file 1000 test_file.csv && ./grading < test_file.csv

#include <algorithm>
#include <iostream>
#include <vector>
#include "grade.h"
#include "seperate.h"

using std::cin;
using std::cout;
using std::sort;
using std::vector;

int main()
{
    vector<Student_info> students;

    // read and store all the students data.
    Student_info record;
    while (read(cin, record))
    {
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // extract the fails
    vector<Student_info> fails = extract_fails(students);

    // write the names and grades of not fails
    cout << "Passing students:\n";
    write_names_and_grade(students);

    // write the names and grades of the fails
    cout << "\nFailing students:\n";
    write_names_and_grade(fails);

    return 0;
}
