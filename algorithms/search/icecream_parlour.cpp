#include <iostream>
#include <vector>
#include <unordered_map>

void get_indices(int, std::vector<int>);

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int m, n, tmp;
        std::vector<int> v;
        std::cin >> m >> n;
        for (int j = 0; j < n; ++j) {
            std::cin >> tmp;
            v.push_back(tmp);
        }
        get_indices(m, v);
    }

    return 0;
}

void get_indices(int m, std::vector<int> v) {
    std::unordered_map<int, int> pairs;
    int len = v.size();

    for (int i = 0; i < len; ++i)
        pairs.insert({v[i], i});

    for (int i = 0; i < len; ++i) {
        if (pairs.find(m - v[i]) != pairs.end()) {
            int j = pairs[m - v[i]];
            if (i < j) {
                std::cout << i + 1 << " " << j + 1 << std::endl;
                return;
            } else if (j < i) {
                std::cout << j + 1 << " " << i + 1 << std::endl;
                return;
            }
        }
    }

    std::cout << "no pair" << std::endl;
}
