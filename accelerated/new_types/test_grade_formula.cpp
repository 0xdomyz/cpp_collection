// usual setup: compile cmd, include io, vector, using namespace std
// g++ -o test_grade_formula test_grade_formula.cpp && ./test_grade_formula
#include <iostream>
#include <vector>

using namespace std;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

int main()
{
    {
        // aaa 76 87 34 98 57
        double midterm = 76;
        double final = 87;
        double homework = 57;

        cout << grade(midterm, final, homework) << endl;
    }
    {
        // 35.0 65.0 44.0 51.0 88.0 9.0 77.0 79.0 89.0 85.0
        // sorted: 9.0 44.0 51.0 77.0 79.0 85.0 88.0 89.0
        double midterm = 35;
        double final = 65;
        double homework = (77.0 + 79.0) / 2;

        cout << grade(midterm, final, homework) << endl;
    }

    {
        // 35.0 65.0 44.0 51.0 88.0
        double midterm = 35;
        double final = 65;
        double homework = 51.0;

        cout << grade(midterm, final, homework) << endl;
    }
}
