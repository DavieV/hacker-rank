#include <iostream>
#include <vector>

int kadane(std::vector<int>);
int non_contiguous(std::vector<int>);
int my_max(std::vector<int>);

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int n, tmp;
        std::vector<int> v;
        std::cin >> n;

        for (int j = 0; j != n; ++j) {
            std::cin >> tmp;
            v.push_back(tmp);
        }

        std::cout << kadane(v) << " " << non_contiguous(v) << std::endl;
    }

    return 0;
}

int kadane(std::vector<int> v) {
    int cur = 0;
    int max = 0;

    for (auto i : v) {
        cur += i;
        if (cur < 0)
            cur = 0;
        if (cur > max)
            max = cur;
    }

    if (max == 0)
        return my_max(v);
    return max;
}

int non_contiguous(std::vector<int> v) {
    int sum = 0;
    for (auto i : v) {
        if (i > 0)
            sum += i;
    }

    if (sum == 0)
        return my_max(v);
    return sum;
}

int my_max(std::vector<int> v) {
    int max = v[0];
    for (unsigned i = 1; i != v.size(); ++i) {
        if (v[i] > max)
            max = v[i];
    }
    return max;
}
