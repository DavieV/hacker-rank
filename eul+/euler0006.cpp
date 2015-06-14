#include <iostream>
#include <utility>

int64_t sum_square_diff(int n);
int64_t abs(int64_t n);

int main() {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << sum_square_diff(n) << std::endl;
    }
    return 0;
}

/*
Return a pair of integers, the first representing the sum of squares of the
numbers from 1 to n. The second representing the square of the summation from
1 to n.
*/
int64_t sum_square_diff(int n) {
    int64_t a = (n * (n + 1) * (2 * n + 1)) / 6;  // Get the sum of squares
    int64_t b = (n * (n + 1)) / 2;  // Get the summation
    b *= b;  // Square it
    return abs(b - a);
}

int64_t abs(int64_t n) {
    if (n < 0)
        return n * -1;
    return n;
}
