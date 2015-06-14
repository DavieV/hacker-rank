#include <iostream>
#include <string>
#include <vector>

int compare(std::string a, std::string b);

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> players;
    std::string tmp;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        players.push_back(tmp);
    }

    int count = 0;
    int max = 0;
    int cur;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cur = compare(players[i], players[j]); 
            if (cur > max) {
                count = 1;
                max = cur; 
            } else if (cur == max) {
                ++count;
            }
        }
    }
    std::cout << max << std::endl << count << std::endl;
    return 0;
}

int compare(std::string a, std::string b) {
    int c = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == '1' || b[i] == '1')
            ++c;
    }
    return c;
}
