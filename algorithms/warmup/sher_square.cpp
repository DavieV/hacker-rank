#include <iostream>
#include <cmath>

bool is_square(int n);

int main() {
    int t, a, b;
    int c = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> a >> b;
        if (is_square(a))
            c += 1;
        c += floor(sqrt(b)) - floor(sqrt(a));
        std::cout << c << std::endl;
        c = 0;
    }
}

bool is_square(int n) {
    int tmp = static_cast<int>(sqrt(n));
    return n == tmp * tmp;
}
