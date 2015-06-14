#include <iostream>

int summation(int);

int main() {
    int t, n;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        std::cin >> n;
        std::cout << summation(n-1) << std::endl;
    }

    return 0;
}

int summation(int n) {
    if (n < 0) return -1;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += i;
    return sum;
}
