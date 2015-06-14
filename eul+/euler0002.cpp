#include <iostream>

long long sum(long long n);

int main() {
    int t;
    long long n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << sum(n) << std::endl;
    }
}

long long sum(long long n) {
    if (n < 2)
        return 0;
    long long p1 = 1, p2 = 2;
    long long cur = 3;
    long long sum = 2;
    while (cur <= n) {
        if (cur % 2 == 0)
            sum += cur;
        p1 = p2;
        p2 = cur;
        cur = p1 + p2;
    }
    return sum;
}
