#include <iostream>
#include <string>
#include <algorithm>

std::string n_permutation(unsigned long);

int main() {
    int t;
    unsigned long n;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << n_permutation(n - 1) << std::endl;
    }

    return 0;
}

std::string n_permutation(unsigned long n) {
    std::string word = "abcdefghijklm";
    for (unsigned long i = 0;
        i != n && std::next_permutation(word.begin(), word.end());
        ++i)
    {}
    return word;
}
