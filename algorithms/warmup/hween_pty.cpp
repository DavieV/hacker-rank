#include <iostream>

long long pieces(long long k);

int main() {
    int t;
    long long k;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> k;
        std::cout << pieces(k) << std::endl;
    }
    return 0;
}

long long pieces(long long k) {
    int tmp = k / 2;
    return (tmp) * (k - tmp);
}
