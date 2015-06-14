#include <iostream>
#include <vector>

int main() {
    int v, n;
    std::vector<int> nums;
    std::cin >> v >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == v) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    return 0;
}
