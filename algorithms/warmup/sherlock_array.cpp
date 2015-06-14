#include <iostream>

bool has_index(int len);
int sum_array(int nums[], int start, int end);

int main() {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        if (has_index(n))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}

bool has_index(int len) {
    int nums[len];
    int tmp;
    for (int i = 0; i < len; ++i) {
        std::cin >> tmp;
        nums[i] = tmp;
    }

    if (len == 1)
        return true;
    if (len == 2)
        return false;

    int pos = 1;
    int sum_left = nums[0];
    int sum_right = sum_array(nums, 2, len);

    while (pos < len - 1) {
        if (sum_left == sum_right) {
            return true;
        }
        sum_left += nums[pos];
        ++pos;
        sum_right -= nums[pos];
    }
    return false;
}

int sum_array(int nums[], int start, int end) {
    int s = 0;
    for (int i = start; i < end; ++i) {
        s += nums[i];
    }
    return s;
}
