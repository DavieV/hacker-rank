#include <iostream>
#include <unordered_set>
#include <cstring>

bool is_pandigital(int, int, int, int);

int main() {
    std::unordered_set<int> products;
    int n, sum = 0;

    std::cin >> n;

    for (int i = 1; i != 1000; ++i) {
        for (int j = i; j != 2000; ++j) {
            if (is_pandigital(i, j, i * j, n)) {
                auto p = products.insert(i * j);
                if (p.second)
                    sum += i * j;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

bool is_pandigital(int x, int y, int z, int n) {
    int occur[10];  // we are dealing with 1-9 pandigital numbers
    memset(occur, 0, sizeof(occur));  // start with 0 occurences for each number
    while (x > 0) {
        ++occur[x%10];
        x /= 10;
    }
    while (y > 0) {
        ++occur[y%10];
        y /= 10;
    }
    while (z > 0) {
        ++occur[z%10];
        z /= 10;
    }
    if (occur[0] != 0) {
        return false;
    }
    for (int i = 1; i != 10; ++i) {
        if (i <= n) {
            if (occur[i] != 1)
                return false;
        } else {
            if (occur[i] != 0)
                return false;
        }
    }
    return true;
}
