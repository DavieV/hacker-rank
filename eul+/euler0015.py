def num_paths(n, m):
    grid = [[0 for i in range(10)] for j in range(10)]

    for i in range(0, n):
        grid[i][0] = 1
    for j in range(0, m):
        grid[0][j] = 1

    for i in range(1, n):
        for j in range(1, m):
            grid[i][j] = grid[i-1][j] + grid[i][j-1]
    
    return grid[n-1][m-1]

for i in range(0, input()):
    line = raw_input().split()
    n = int(line[0])
    m = int(line[1])
    print num_paths(n, m)