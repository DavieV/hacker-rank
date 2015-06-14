#include <iostream>

int digits(int m);

int main() {
    int n;
    std::cin >> n;
    int m;
    for (int i = 0; i < n; ++i) {
        std::cin >> m;
        std::cout << digits(m) << std::endl;
    }
    return 0;
}

int digits(int m) {
    int tmp = m;
    int c = 0;
    int dig;
    while (tmp > 0) {
        dig = tmp % 10;
        if (dig != 0) {
            if (m % dig == 0)
                ++c;
        }
        tmp /= 10;
    }
    return c;
}
