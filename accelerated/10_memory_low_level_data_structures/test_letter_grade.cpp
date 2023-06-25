// g++ test_letter_grade.cpp -o test_letter_grade && echo "5 45 59.5 65 72.5 81 85 87 92 99" | ./test_letter_grade

#include <iostream>
#include <vector>
#include <string>
#include "letter_grade.h"

using namespace std;

int main()
{
    vector<double> grades;
    vector<string> letter_grades;

    double grade;
    while (cin >> grade)
    {
        grades.push_back(grade);
    }

    for (vector<double>::size_type i = 0; i < grades.size(); ++i)
    {
        letter_grades.push_back(letter_grade(grades[i]));
    }

    for (vector<string>::size_type i = 0; i < letter_grades.size(); ++i)
    {
        cout << grades[i] << " " << letter_grades[i] << endl;
    }

    return 0;
}
