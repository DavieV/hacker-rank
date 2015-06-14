#include <iostream>
#include <vector>

int cut(int nums[], int len, int m);
int min(int nums[], int len);

int main() {
    int n;
    std::cin >> n;
    int tmp;
    int nums[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        nums[i] = tmp;
    }

    int m = min(nums, n);

    int count;
    while ((count = cut(nums, n, m)) > 0) {
        std::cout << count << std::endl;
        m = min(nums, n);
    }
    return 0;
}

int cut(int nums[], int len, int m) {
    int c = 0;
    for (int i = 0; i < len; ++i) {
        if (nums[i] > 0) {
            nums[i] -= m;
            ++c;
        }
    }
    return c;
}

int min(int nums[], int len) {
    int m = 1000;
    for (int i = 0; i < len; ++i) {
        if (nums[i] < m && nums[i] > 0)
            m = nums[i];
    }
    return m;
}
