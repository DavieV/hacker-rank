#include <iostream>

int main() {
    int n, x, id;
    uint64_t p, tmp, max;

    std::cin >> n >> p >> x;

    for (int i = 1; i <= n; ++i) {
        std::cin >> tmp;
        if (p * tmp > max) {
            max = p * tmp;
            id = i;
        }
        p -= x;
    }

    std::cout << id << std::endl;

    return 0;
}
