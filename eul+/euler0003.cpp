/*
Currently fails on the final test case
*/

#include <iostream>
#include <cstring>
#include <vector>

#define MAX 1000000

bool is_prime(int64_t n, bool s[], std::vector<int> p);
void del_mult(int p, bool s[]);
int next_prime(int p, bool s[]);
int64_t largest_factor(int64_t n, std::vector<int> p);

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

    // Create a vector of prime numbers
    std::vector<int> primes;
    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    int t;  // Number of test cases
    int64_t n;  // Test input

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        if (is_prime(n, sieve, primes))
            std::cout << n << std::endl;
        else
            std::cout << largest_factor(n, primes) << std::endl;
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

bool is_prime(int64_t n, bool s[], std::vector<int> p) {
    if (n < MAX)
        return s[n];
    for (int i : p) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int64_t largest_factor(int64_t n, std::vector<int> p) {
    int i = 0;
    int cur = p[i];
    int max = 1;
    while (cur * cur <= n) {
        if (n % cur == 0) {
            n /= cur;
            max = cur;
        } else {
            ++i;
            cur = p[i];
        }
    }
    if (n > max)
        max = n;
    return max;
}
