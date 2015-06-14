#include <iostream>

int main() {
    int t, n, c, m, w;
    int total = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n >> c >> m;
        w = n / c;
        total += w;
        while (w >= m) {
            total += w / m;
            w = (w / m) + (w % m);
        }
        std::cout << total << std::endl;
        total = 0;
    }
    return 0;
}
