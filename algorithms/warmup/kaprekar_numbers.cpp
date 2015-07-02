#include <iostream>
#include <cmath>

int64_t num_len(int64_t);
bool is_kaprekar(int64_t);

int main() {
    int64_t p, q;
    std::cin >> p >> q;

    bool valid = false;
    for (int64_t i = p; i <= q; ++i) {
        if (is_kaprekar(i)) {
            valid = true;
            std::cout << i << " ";
        }
    }

    if (valid)
        std::cout << std::endl;
    else
        std::cout << "INVALID RANGE" << std::endl;

    return 0;
}

int64_t num_len(int64_t n) {
    int64_t l = 0;
    while (n > 0) {
        n /= 10;
        ++l;
    }
    return l;
}

bool is_kaprekar(int64_t n) {
    int64_t num1 = 0, num2 = 0;
    int64_t tmp = n * n;
    int64_t len = num_len(tmp);

    // get the first d or d+1 digits
    if (len % 2 == 0) {
        for (int64_t i = 0; i < len / 2; ++i, tmp /= 10)
            num1 = num1 + (std::pow(10, i) * (tmp % 10));
    } else {
        for (int64_t i = 0; i <= len / 2; ++i, tmp /= 10)
            num1 = num1 + (std::pow(10, i) * (tmp % 10));
    }

    // get the remaining d digits
    for (int64_t i = 0; tmp > 0; ++i, tmp /= 10)
        num2 = num2 + (std::pow(10, i) * (tmp % 10));

    return num1 + num2 == n;
}
