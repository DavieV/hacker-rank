#include <iostream>
#include <string>

int num_removals(std::string a, std::string b);
unsigned int my_abs(int n);

int main() {
    std::string a, b;

    std::cin >> a >> b;

    std::cout << num_removals(a, b) << std::endl;
    return 0;
}

int num_removals(std::string a, std::string b) {
    unsigned int occur_a[26] = {0};
    unsigned int occur_b[26] = {0};

    for (auto c : a)
        ++occur_a[c - 'a'];
    for (auto c : b)
        ++occur_b[c - 'a'];

    unsigned int cnt = 0;

    for (int i = 0; i < 26; ++i) {
        cnt += abs(occur_a[i] - occur_b[i]);
    }
    return cnt;
}

unsigned int my_abs(int n) {
    return (n < 0) ? (-1 * n) : n;
}
