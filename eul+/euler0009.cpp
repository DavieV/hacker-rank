/*
    Too slow, need to use Euclid's algorithm to generate all of the pythagorean
    triples quickly.
*/

#include <iostream>

int triple(int n);
bool isPythagTriple(int a, int b, int c);

int main() {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << triple(n) << std::endl;
    }
    return 0;
}

int triple(int n) {
    int max = -1;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n - i; j++) {
            int k = n - i - j;
            if (isPythagTriple(i, j, k))
                max = std::max(max, i * j * k);
        }
    }
    return max;
}

bool isPythagTriple(int a, int b, int c) {
    return a * a + b * b == c * c;
}
