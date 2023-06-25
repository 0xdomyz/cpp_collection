#include <map>
#include <string>
#include <stdexcept>
#include "letter_grades.h"

using namespace std;

string score_to_letter_grades(double score)
{
    static map<double, string> score_to_letter_grades_map;
    if (score_to_letter_grades_map.empty())
    {
        score_to_letter_grades_map[60] = "F";
        score_to_letter_grades_map[70] = "D";
        score_to_letter_grades_map[80] = "C";
        score_to_letter_grades_map[90] = "B";
        score_to_letter_grades_map[101] = "A";
    }
    for (auto it = score_to_letter_grades_map.begin();
         it != score_to_letter_grades_map.end(); ++it)
    {
        if (score < it->first)
        {
            return it->second;
        }
    }
    // raise
    throw domain_error("score_to_letter_grades: score out of range");
}
