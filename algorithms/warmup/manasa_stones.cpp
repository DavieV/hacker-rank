#include <iostream>
#include <set>

void final_stone(int n, int a, int b);

int main() {
    int t;
    std::cin >> t;
    int n;
    int a, b;
    for (int i = 0; i < t; ++i) {
        std::cin >> n >> a >> b;
        final_stone(n, a, b);
    }
    return 0;
}

void final_stone(int n, int a, int b) {
    std::set<int> stones;
    for (int i = 0; i < n; ++i) {
        stones.insert(((n - i - 1) * a) + (b * i));
    }

    for (int i : stones) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
