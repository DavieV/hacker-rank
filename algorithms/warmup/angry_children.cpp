#include <iostream>
#include <vector>
#include <algorithm>

int min_dif(std::vector<int> v, int k);

int main() {
    int n, k;
    std::vector<int> amounts;

    std::cin >> n;
    std::cin >> k;
    
    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        amounts.push_back(tmp);
    }

    std::sort(amounts.begin(), amounts.end());
    std::cout << min_dif(amounts, k) << std::endl;

    return 0;
}

int min_dif(std::vector<int> v, int k) {
    int min = v[k-1] - v[0];
    for (int i = 1; i < v.size() - k; ++i) {
        if (v[k+i-1] - v[i] < min)
            min = v[k+i-1] - v[i];
    }
    return min;
}
