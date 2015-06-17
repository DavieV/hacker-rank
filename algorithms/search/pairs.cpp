#include <iostream>
#include <vector>
#include <unordered_set>

int count_pairs(std::vector<int>, int);

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> v;
    for (int tmp; std::cin >> tmp;)
        v.push_back(tmp);

    std::cout << count_pairs(v, k) << std::endl;

    return 0;
}

// Return amount of pairs of ints in the set that have a difference of k
int count_pairs(std::vector<int> v, int k) {
    std::unordered_set<int> set;
    int c = 0;

    for (int i : v)
        set.insert(i + k);

    for (int i : v) {
        if (set.find(i) != set.end())
            ++c;
    }

    return c;
}
