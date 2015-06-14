#include <iostream>

int main() {
    int l, r;
    std::cin >> l >> r;

    int max = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = i; j <= r; ++j) {
            if (i <= j && (i ^ j) > max)
                max = i ^ j;
        }
    }
    std::cout << max << std::endl;
    return 0;
}
