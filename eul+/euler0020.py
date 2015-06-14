def sum_digits(n):
    s = 0
    while n > 0:
        s += n % 10
        n /= 10
    return s

import math

for i in range(0, input()):
    print sum_digits(math.factorial(input()))
