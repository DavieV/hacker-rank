#include <iostream>

bool power_2(uint64_t);
uint64_t next_largest(uint64_t);
int highest_bit(uint64_t);
void find_winner(uint64_t);

int main() {
    int t;
    std::cin >> t;
    uint64_t n;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        find_winner(n);
    }
}

bool power_2(uint64_t n) {
    return n != 0 && !(n & (n - 1));
}

uint64_t next_largest(uint64_t n) {
    return 1UL << (highest_bit(n) - 1);
}

int highest_bit(uint64_t n) {
    uint64_t start = (1UL << 63);
    int pos = 64;
    while (!(start & n)) {
        start >>= 1;
        --pos;
    }
    return pos;
}

void find_winner(uint64_t n) {
    int moves = 1;
    while (n != 1) {
        if (power_2(n))
            n -= n / 2;
        else
            n -= next_largest(n);
        ++moves;
    }
    if (moves % 2 == 0)
        std::cout << "Louise" << std::endl;
    else
        std::cout << "Richard" << std::endl;
}
