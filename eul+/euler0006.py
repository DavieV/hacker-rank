def sum_square_diff(n):
    a = (n * (n + 1) * (2 * n + 1)) / 6
    b = (n * (n + 1)) / 2
    b *= b
    return abs(b - a)

for i in range(0, input()):
    print sum_square_diff(input())