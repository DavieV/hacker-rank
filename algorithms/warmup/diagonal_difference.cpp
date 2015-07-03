#include <iostream>

int my_abs(int);

int main() {
    int n;
    std::cin >> n;

    int sum1 = 0, sum2 = 0;
    int tmp;

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cin >> tmp;
            if (i == j)
                sum1 += tmp;
            if (i + j == n - 1)
                sum2 += tmp;
        }
    }

    std::cout << my_abs(sum1 - sum2) << std::endl;

    return 0;
}

int my_abs(int n) {
    return (n > 0) ? n : -n;
}
