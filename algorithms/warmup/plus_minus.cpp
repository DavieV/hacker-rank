#include <iostream>
#include <cstdio>

int main() {
    float n;
    float pos = 0, neg = 0, zero = 0;

    std::cin >> n;

    for (int tmp; std::cin >> tmp;) {
        if (tmp < 0) ++neg;
        else if (tmp > 0) ++pos;
        else ++zero;
    }

    printf("%0.3f\n%0.3f\n%0.3f\n", (pos / n), (neg / n), (zero / n));

    return 0;
}