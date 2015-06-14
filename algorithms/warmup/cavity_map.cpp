#include <iostream>
#include <string>

void find_cavities(int len, int **map);
void fill_map(int len, int **map, int i, std::string n);

int main() {
    int n;
    std::cin >> n;

    int **map = new int *[n];
    for (int i = 0; i < n; ++i)
        map[i] = new int[n];

    std::string tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        fill_map(n, map, i, tmp);
    }

    find_cavities(n, map);
}

void fill_map(int len, int **map, int i, std::string n) {
    for (int c = 0; c < len; ++c) {
        map[i][c] = n[c] - '0';
    }
}

void find_cavities(int len, int **map) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (i > 0 && i < len - 1 && j > 0 && j < len - 1) {
                if (map[i-1][j] < map[i][j] && map[i+1][j] < map[i][j] && map[i][j-1] < map[i][j] && map[i][j+1] < map[i][j]) {
                    std::cout << "X";
                } else {
                    std::cout << map[i][j];
                }
            } else {
                std::cout << map[i][j];
            }
        }
        std::cout << std::endl;
    }
}
