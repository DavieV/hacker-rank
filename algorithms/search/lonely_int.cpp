#include <iostream>

int main() {
    int n;
    int cur = 0;

    std::cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        cur ^= tmp;
    }

    std::cout << cur << std::endl;
    return 0;
}
