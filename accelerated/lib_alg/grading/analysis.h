#include "Student_info.h"
#include "container.h"
#include <string>

bool did_all_hw(const Student_info &s);

double median_analysis(const container<Student_info> &students);

double average_analysis(const container<Student_info> &students);

double optimistic_median_analysis(const container<Student_info> &students);

void write_analysis(std::ostream &out, const std::string &name,
                    double analysis(const container<Student_info> &),
                    const container<Student_info> &did,
                    const container<Student_info> &didnt);
