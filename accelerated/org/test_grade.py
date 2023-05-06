#  python3.11 test_grade.py

import numpy as np


def grade(midterm,final, *args):

    homework = np.median(np.array(args))

    res= 0.2 * midterm + 0.4 * final + 0.4 * homework
    print("Your final grade is: ", res)

with open("grades.txt", "r") as f:
    for line in f:
        line = line.split()
        grade(int(line[1]), float(line[2]), [float(i) for i in line[3:]])