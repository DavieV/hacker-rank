#include <iostream>

int min_draws(int);

int main() {
    int t, n;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        std::cin >> n;
        std::cout << min_draws(n) << std::endl;
    }

    return 0;
}

// Output the minimum number of draws to find a pair for n pairs of socks
int min_draws(int n) {
    return n + 1;
}
