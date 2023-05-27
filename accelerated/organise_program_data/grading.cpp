// compile: g++ -o grading letter_grades.cpp grading.cpp Student_info.cpp grade.cpp median.cpp && ./grading < grades.txt

// organization
// grade.cpp uses grade.h, median.h, Student_info.h
// grade.h uses Student_info.h
// grading.cpp uses grade.h

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include "grade.h"
#include "letter_grades.h"
// #include "Student_info.h" // not needed because grade.h includes it

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::map;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0; // the length of the longest name
    // read and store all the students data.
    // Invariant: students contains all the student records read so far
    // maxlen contains the length of the longest name in students
    while (read(cin, record))
    {
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    // also put into right map
    map<string, float> grade_to_count_map;

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        // compute and write the grade
        try
        {
            double final_grade = grade(students[i]);

            // put into right map
            string letter_grade = score_to_letter_grades(final_grade);
            grade_to_count_map[letter_grade] += 1;

            // display score
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }

    // display grade distribution
    for (auto it = grade_to_count_map.begin();
         it != grade_to_count_map.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
