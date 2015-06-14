#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    int n, k, c, tmp;
    for (int i = 0; i != t; ++i) {
        std::cin >> n >> k;
        c = 0;
        for (int j = 0; j != n; ++j) {
            std::cin >> tmp;
            if (tmp <= 0)
                ++c;
        }
        if (c < k)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}
