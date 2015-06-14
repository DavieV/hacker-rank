// Given a string, find the next string that is lexicographically greater

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i != n; ++i) {
        std::string s;
        std::cin >> s;
        if (std::next_permutation(std::begin(s), std::end(s)))
            std::cout << s << std::endl;
        else
            std::cout << "no answer" << std::endl;
    }

    return 0;
}
