#include <iostream>
int main() {
    long long total = 0;
    long long n, m, a, b, k;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> k;
        total += k * (b - a + 1);
    }
    std::cout << total / n << std::endl;
    return 0;
}
