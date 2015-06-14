#include <iostream>
#include <vector>

int gcd(int a, int b);
bool valid_subset(std::vector<int> nums);

int main() {
    int t;
    std::cin >> t;
    std::vector<int> array;
    int n, a;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            array.push_back(a);
        }
        if (valid_subset(array))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
        array.clear();
    }
}

int gcd(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

bool valid_subset(std::vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1)
            return true;
        for (int j = i+1; j < nums.size(); ++j) {
            if (gcd(nums[i], nums[j]) == 1)
                return true;
        }
    }
    return false;
}
