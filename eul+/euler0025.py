import math

def num_len(n):
    l = 0
    while (n > 0):
        n /= 10
        l += 1
    return l

def find_fib(k):
    cur = 1
    n1 = 1
    n2 = 2
    n = 1
    while (num_len(cur) < k):
        cur = n1
        n1 = n2
        n2 = cur + n1
        n += 1
    return n

t = input()

for i in range(t):
    k = input()
    if (k <= 10000):
        print find_fib(k)
    
    n = int(math.ceil(((k - 1) * math.log(10) + (math.log(5) / 2)) / math.log(1.6180)))
    print n
