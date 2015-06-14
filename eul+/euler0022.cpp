#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int name_score(std::string n, int q);

int main() {
    int t;
    std::string tmp;
    std::vector<std::string> names;

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> tmp;
        names.push_back(tmp);
    }

    std::sort(names.begin(), names.end());
    std::unordered_map<std::string, int> keys;

    for (int i = 0; i < names.size(); ++i)
        keys[names[i]] = i + 1;

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> tmp;
        std::cout << name_score(tmp, keys[tmp]) << std::endl;
    }
    return 0;
}

int name_score(std::string name, int n) {
    int sum = 0;
    for (char i : name)
        sum += i - 'A' + 1;
    return sum * n;
}
