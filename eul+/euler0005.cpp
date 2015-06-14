#include <iostream>

bool is_valid(int n, int lim);

int main() {
    int t, n, c;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {  // Loop through each test case
        std::cin >> n;
        c = 1;
        while (!is_valid(c, n)) // Loop until a valid c is found
            ++c;
        std::cout << c << std::endl;
    }
    return 0;
}

// Determine whether all of the numbers from 1-lim evenly divide n
bool is_valid(int n, int lim) {
    for (int i = 2; i <= lim; i++) {
        if (n % i != 0) return false;
    }
    return true;
}
