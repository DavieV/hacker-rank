#include <iostream>

bool is_valid(int, int);
int my_pow(int, int);

int main() {
    int n, sum = 0;
    std::cin >> n;

    for (int i = 10; i < 1000000; ++i) {
        if (is_valid(i, n))
            sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}

bool is_valid(int n, int b) {
    int tmp = n;
    int sum = 0;
    while (tmp > 0) {
        sum += my_pow(tmp % 10, b);
        tmp /= 10;
    }
    return n == sum;
}

int my_pow(int a, int b) {
    int n = a;
    for (int i = 0; i != b-1; ++i) {
        n *= a;
    }
    return n;
}
