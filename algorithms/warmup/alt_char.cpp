#include <iostream>
#include <string>

int del(std::string w);

int main() {
    int t;
    std::string word;

    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> word;
        std::cout << del(word) << std::endl;
    }
    return 0;
}

int del(std::string w) {
    unsigned char cur = w[0];
    int del = 0;
    for (int i = 1; i < w.length(); ++i) {
        if (w[i] == cur)
            ++del;
        else
            cur = w[i];
    }
    return del;
}
