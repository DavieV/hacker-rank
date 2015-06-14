#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> prices;
    int tmp;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        prices.push_back(tmp);
    }

    std::sort(prices.begin(), prices.end());
    int count = 0;

    for (int i = 0; prices[i] < k && i < n; ++i) {
        ++count;
        k -= prices[i];
    }
    std::cout << count << std::endl;
    return 0;
}
