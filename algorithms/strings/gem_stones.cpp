#include <iostream>
#include <string>
#include <vector>
#include <map>

int num_gems(std::vector<std::string> rocks);

int main() {
    int n;
    std::vector<std::string> rocks;
    std::string tmp;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        rocks.push_back(tmp);
    }

    std::cout << num_gems(rocks) << std::endl;

    return 0;
}

int num_gems(std::vector<std::string> rocks) {
    unsigned int occur[26] = {0};
    std::map<char, bool> in_rock;

    for (auto s : rocks) {
        for (char c : s) {
            if (in_rock.find(c) == in_rock.end()) {
                ++occur[c - 'a'];
                in_rock[c] = true;
            }
        }
        in_rock.clear();
    }

    unsigned int cnt = 0;
    for (auto n : occur) {
        if (n == rocks.size())
            ++cnt;
    }

    return cnt;
}
