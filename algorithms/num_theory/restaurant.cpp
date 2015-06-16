#include <iostream>

int gcd(int m, int n);
int max_squares(int, int);

int main() {
    int t;      // number of test cases
    int l, b;   // dimensions of the bread

    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        std::cin >> l >> b;
        std::cout << max_squares(l, b) << std::endl;
    }

    return 0;
}

int max_squares(int l, int b) {
    int d = gcd(l, b);
    return (l / d) * (b / d);
}

int gcd(int m, int n) {
    int r = m % n;
    while (r) {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
