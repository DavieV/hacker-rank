#include <iostream>

void fill_grid(uint64_t**, int, int);

int main() {
    int t;

    std::cin >> t;

    int m, n;
    for (int i = 0; i < t; ++i) {
        std::cin >> m >> n;

        // Allocate the m by n grid
        uint64_t** grid = new uint64_t*[m+1];
        for (int j = 0; j <= m; ++j)
            grid[j] = new uint64_t[n+1];

        fill_grid(grid, m, n);

        // The maximum number of paths will be stored at the beginning
        std::cout << grid[0][0] << std::endl;

        // Deallocate the grid in memory
        for (int j = 0; j < m; ++j)
            delete[] grid[j];
    }

    return 0;
}

void fill_grid(uint64_t** grid, int m, int n) {
    // First set the number of paths on left and right edges to 1
    for (int i = 0; i <= m; ++i)
        grid[i][n] = 1;

    for (int i = 0; i <= n; ++i)
        grid[m][i] = 1;

    // Go through the grid in reverse, and set the value at position (i, j)
    // equal to ((i+1, j) + (i, j+1)) % (10^9 + 7)
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            grid[i][j] = (grid[i+1][j] + grid[i][j+1]) % 1000000007; 
        }
    }
}
