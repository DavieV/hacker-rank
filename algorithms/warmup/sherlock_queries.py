n = input()
m = input()

A = []
for i in range(0, n):
    A.append(input())

B = []
C = []

for i in range(0, m):
    B.append(input())

for i in range(0, m):
    C.append(input())

for i in range(0, m):
    for j in range(0, n):
        if j % B[i] == 0:
            A[j] = A[j] * C[i]

for n in A:
    print n % ((10 ** 9) + 7)