// g++ const_expr_template_example.cpp -o const_expr_template_example && ./const_expr_template_example

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct Student
{
    std::string name;
    int grade;
};

bool compare(const Student &a, const Student &b)
{
    return a.grade < b.grade;
}

template <typename T>
void sortStudents(T &students)
{
    if constexpr (std::is_same_v<T, std::vector<Student>>)
    {
        std::sort(students.begin(), students.end(), compare);
    }
    else if constexpr (std::is_same_v<T, std::list<Student>>)
    {
        students.sort(compare);
    }
}

int main()
{
    std::vector<Student> studentVector = {{"Alice", 90}, {"Bob", 80}, {"Charlie", 70}};
    std::list<Student> studentList = {{"Alice", 90}, {"Bob", 80}, {"Charlie", 70}};

    sortStudents(studentVector);
    sortStudents(studentList);

    for (const auto &student : studentVector)
    {
        std::cout << student.name << ": " << student.grade << '\n';
    }

    for (const auto &student : studentList)
    {
        std::cout << student.name << ": " << student.grade << '\n';
    }

    return 0;
}
