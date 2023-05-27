// g++ multi_grade.cpp -o multi_grade && ./multi_grade

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// push back new name and grade into the vectors
void process(vector<string> &names, vector<double> &grades)
{
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for and read the homework grades
    cout << "Enter all your homework grades, "
            "3 homework grades: ";
    vector<double> homework;
    double x;

    //
    cin >> x;
    homework.push_back(x);
    cin >> x;
    homework.push_back(x);
    cin >> x;
    homework.push_back(x);

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    // sort the grades
    sort(homework.begin(), homework.end());

    // compute the median homework grade
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
                           : homework[mid];

    // compute and write the final grade
    streamsize prec = cout.precision();
    double final_grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
    cout << "Your final grade is " << setprecision(3)
         << final_grade
         << setprecision(prec) << endl;

    // push back new name and grade into the vectors
    names.push_back(name);
    grades.push_back(final_grade);
}

int main()
{
    vector<string> names;
    vector<double> final_grades;

    // read and store the data
    process(names, final_grades);
    process(names, final_grades);

    return 0;
}
