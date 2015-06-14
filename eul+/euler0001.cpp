#include <iostream>

long sum(long n);

int main() {
    int t;
    long n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << sum(n) << std::endl;
    }
    return 0;
}

long sum(long n) {
    long threes = (n-1) / 3 * ((n-1) / 3 + 1) / 2 * 3;
    long fives = (n-1) / 5 * ((n-1) / 5 + 1) / 2 * 5;
    long fifteens = (n-1) / 15 * ((n-1) / 15 + 1) / 2 * 15;
    return threes + fives - fifteens;
}
