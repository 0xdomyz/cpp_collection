// g++ Student_info.cpp -o Student_info && ./Student_info

#include <iostream>
#include <string>
#include <vector>

double average(std::vector<double> vec)
{
    double sum = 0;
    for (auto i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum / vec.size();
}

struct Student_info
{
    double final_grade;
    std::string name;

    Student_info(std::string name, double midterm, double final, std::vector<double> homework)
        : name(name)
    {
        final_grade = grade(midterm, final, homework);
    }

    double
    grade(double midterm, double final, std::vector<double> homework)
    {
        return 0.2 * midterm + 0.4 * final + 0.4 * average(homework);
    }
};

int main(void)
{
    Student_info record{"John", 23, 45.6, {12, 13.4, 11, 56, 78.9, 101}};
    std::cout << record.name << " " << record.final_grade << std::endl;
}