#include <iostream>
#include <vector>
#include <cstring>

#define MAX 1000000

void del_mult(int p, bool s[]);
int next_prime(int p, bool s[]);

int main() {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    // Fill out the sieve of primes
    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    std::vector<int> primes;
    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << primes[n-1] << std::endl;
    }
    return 0;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i += p)
        s[i] = false;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}
