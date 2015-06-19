#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

std::string encrypt(std::string);

int main() {
    std::string s;
    std::cin >> s;
    std::cout << encrypt(s) << std::endl;
    return 0;
}

std::string encrypt(std::string s) {
    int len = s.length();
    int cols = std::ceil(std::sqrt(len));
    int rows = std::floor(std::sqrt(len));

    while (cols * rows < len) {
        if (rows < cols)
            ++rows;
        else
            ++cols;
    }

    int s_index = 0;
    char grid[rows][cols];
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (s_index < len)
                grid[i][j] = s[s_index++];
        }
    }

    std::string msg = "";

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (grid[j][i] != 0)
                msg += grid[j][i];
        }
        msg += " ";
    }

    return msg;
}
