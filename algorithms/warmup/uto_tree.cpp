#include <iostream>

int height(int n);

int main() {
    int t;
    int n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << height(n) << std::endl;
    }
    return 0;
}

int height(int n) {
    int base = 1;
    int mode = 0;
    while (n > 0) {
        if (mode == 0) {
            base *= 2;
            mode = 1;
        } else {
            ++base;
            mode = 0;
        }
        --n;
    }
    return base;
}
