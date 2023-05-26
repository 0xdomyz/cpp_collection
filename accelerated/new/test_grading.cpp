// usual setup: compile cmd, include io, vector, using namespace std
// g++ -o test_grading test_grading.cpp && ./test_grading
#include <iostream>
#include <vector>

using namespace std;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

int main()
{
    // aaa 76 87 34 98 57
    double midterm = 76;
    double final = 87;
    double homework = 57;

    cout << grade(midterm, final, homework) << endl;
}
