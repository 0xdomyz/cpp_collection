# calculate sin and cos of a given number

import math


def sin_cos(x):
    sin = math.sin(x)
    cos = math.cos(x)
    return sin, cos


for i in range(0, 10):
    print(f"x = {i/10}, sin(x) = {sin_cos(i/10)[0]}, cos(x) = {sin_cos(i/10)[1]})")
