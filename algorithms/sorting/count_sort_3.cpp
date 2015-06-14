#include <iostream>
#include <string>
#include <cstring>

int main() {
    int n;
    std::cin >> n;
    int freq[100];
    memset(freq, 0, sizeof(freq));
    int tmp;
    std::string tmp_str;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        std::cin >> tmp_str;
        ++freq[tmp];
    }

    for (int i = 1; i < 100; ++i)
        freq[i] += freq[i-1];

    for (int i = 0; i < 100; ++i)
        std::cout << freq[i] << " ";
    std::cout << std::endl;
    return 0;
}
