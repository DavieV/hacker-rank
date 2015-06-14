// Find the largest product of K consecutive digits, within an
// N digit number

#include <iostream>
#include <string>

int64_t max_product(std::string, int);

int main() {
    int T, N, K;
    std::string num;

    std::cin >> T;

    for (int i = 0; i != T; ++i) {
        std::cin >> N >> K >> num;
        std::cout << max_product(num, K) << std::endl;
    }

    return 0;
}

int64_t max_product(std::string N, int K) {
    int64_t max = 0;
    int64_t cur = 1;
    int num_digits = 0;
    int len = N.length();
    for (int i = 0; i != len; ++i) {
        cur *= N[i] - '0';

        if (num_digits < K)
            ++num_digits;
        else
            cur /= N[i-K] - '0';

        if (cur > max && num_digits == K)
            max = cur;

        if (cur == 0) {
            cur = 1;
            num_digits = 0;
        }
    }

    return max;
}
