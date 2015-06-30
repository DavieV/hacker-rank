#include <iostream>
#include <cstring>
#include <cmath>

void remove_multiples(bool*, int, int);
int next_prime(bool*, int, int);
bool is_valid(bool*, int, int);
int num_len(int);

int main() {
    int n;

    std::cin >> n;

    bool* sieve = new bool[n];
    memset(sieve, true, sizeof(bool) * n);
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    for (int i = 0; i * i < n; ++i) {
        remove_multiples(sieve, prime, n);
        prime = next_prime(sieve, prime, n);
    }

    uint64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sieve[i] && is_valid(sieve, i, n))
            sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}

void remove_multiples(bool* s, int p, int n) {
    for (int i = p * p; i < n; i += p)
        s[i] = false;
}

int next_prime(bool* s, int p, int n) {
    while (p < n - 1 && !s[++p]);
    return p;
}

bool is_valid(bool* s, int p, int n) {
    int l = num_len(p);
    int end;
    for (int i = 0; i < l; ++i) {
        if (p >= n || !s[p]) return false;
        // Rotate the number
        end = p % 10;
        p /= 10;
        p = (end * std::pow(10, l - 1)) + p;
    }
    return true;
}

int num_len(int n) {
    int l = 0;
    while (n > 0) {
        ++l;
        n /= 10;
    }
    return l;
}
