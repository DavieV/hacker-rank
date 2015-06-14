#include <iostream>

unsigned factorial(unsigned);
unsigned sum_factorials(unsigned);

int main() {
    int n, sum = 0;
    std::cin >> n;

    for (int i = 10; i != n; ++i) {
        if (sum_factorials(i) % i == 0)
            sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}

unsigned factorial(unsigned n) {
    if (n == 0)
        return 1;

    unsigned p = 1;
    for (unsigned i = 1; i != (n+1); ++i)
        p *= i;

    return p;
}

unsigned sum_factorials(unsigned n) {
    unsigned sum = 0;
    while (n > 0) {
        sum += factorial(n % 10);
        n /= 10;
    }
    return sum;
}
