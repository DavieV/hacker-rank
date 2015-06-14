/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23. The path is denoted by numbers in bold.

3 
74 
246 
8593

That is, 3+7+4+9=23.

Find the maximum total from top to bottom of the triangle given in input.

** This code can also be used as a solution to problem #67 **
*/

#include <iostream>
#include <cstring>

int my_max(int, int);
int max_path(int);

int main() {
    int t;

    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int n;
        std::cin >> n;
        std::cout << max_path(n) << std::endl;
    }

    return 0;
}

int my_max(int a, int b) {
    return (a > b) ? a : b;
}

int max_path(int n) {
    int triangle[n][n];
    memset(triangle, 0, n * n * sizeof(int));

    // read in the contents of the triangle
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != i + 1; ++j) {
            std::cin >> triangle[i][j];
        }
    }

    // find the path length using a bottom-up approach
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            triangle[i][j] += my_max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}
