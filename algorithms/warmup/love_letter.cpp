#include <iostream>
#include <string>

int min_changes(std::string w);

int main() {
    int t;
    std::string word;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> word;
        std::cout << min_changes(word) << std::endl;
    }
    return 0;
}

int min_changes(std::string w) {
    int c = 0;
    for (int i = 0; i < w.length() / 2; ++i) {
        if (w[i] > w[w.length()-i-1]) {
            c += w[i] - w[w.length()-i-1];
        } else if (w[i] < w[w.length()-i-1]) {
            c += w[w.length()-i-1] - w[i];
        }
    }
    return c;
}
