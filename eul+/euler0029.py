n = input()
nums = set([])
for i in range(2, n+1):
    for j in range(2, n+1):
        nums.add(i ** j)
print len(nums)