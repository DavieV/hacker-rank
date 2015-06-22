#include <iostream>
#include <string>

uint64_t score(std::string);
uint64_t summation(uint64_t);

int main() {
    int n;
    std::string s;

    std::cin >> n >> s;
    std::cout << score(s) << std::endl;

    return 0;
}

uint64_t score(std::string s) {
    uint64_t sum = s.length();  // Each letter scores 1 point
    uint64_t occurs[26] = {0};  // count occurences of each character

    for (char c : s)
        ++occurs[c - 'a'];

    for (auto i : occurs)
        sum += summation(i);

    return sum;
}

uint64_t summation(uint64_t n) {
    return n * (n - 1) / 2;
}
