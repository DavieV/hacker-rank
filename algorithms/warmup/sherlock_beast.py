def pswd(n):
    if n % 3 == 0:
        return "5" * n

    pswd = ""
    while (n % 3 != 0):
        pswd = pswd + "33333"
        n -= 5
        if n < 0:
            return -1
    pswd = "5" * n + pswd
    return pswd

for i in range(0, input()):
    print pswd(input())