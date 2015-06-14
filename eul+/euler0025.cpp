#include <iostream>
#include <cmath>

int find_fib(int);
int num_len(int);

int main() {
    int t, k;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        std::cin >> k;
        if (k <= 10) {
            std::cout << find_fib(k) << std::endl;
        } else {
            double n = round(((k - 1) * log(10) + (log(5) / 2)) / log(1.6180));
            std::cout << n << std::endl;
        }
    }
}

int find_fib(int k) {
    int cur = 1, next1 = 1, next2 = 2, n = 1;
    while (num_len(cur) < k) {
        cur = next1;
        next1 = next2;
        next2 = cur + next1;
        ++n;
    }
    return n;
}

int num_len(int n) {
    int len = 0;
    while (n > 0) {
        n /= 10;
        ++len;
    }
    return len;
}
