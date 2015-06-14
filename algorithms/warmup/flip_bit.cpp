#include <iostream>
#include <climits>

int main() {
    int t;
    unsigned int n;

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << (n ^ UINT_MAX) << std::endl;
    }

    return 0;
}
