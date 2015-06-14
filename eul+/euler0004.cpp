#include <iostream>
#include <vector>
#include <algorithm>

int reverse_num(int n);
bool is_palindrome(int n);
int find_num(int n, std::vector<int> p);
std::vector<int> get_palindromes();

int main() {
    int t, n;
    std::cin >> t;
    std::vector<int> palindromes = get_palindromes();

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << find_num(n, palindromes) << std::endl;
    }
    return 0;
}

int reverse_num(int n) {
    int rev = 0;
    while (n > 0) {
        rev = (rev * 10) + n % 10;
        n /= 10;
    }
    return rev;
}

bool is_palindrome(int n) {
    return n == reverse_num(n);
}

// Find the largest number in the list that is less than n
int find_num(int n, std::vector<int> p) {
    int lo = 0, hi = p.size() - 1, mid = hi / 2;
    while (lo <= hi) {
        if (p[mid] < n && p[mid+1] > n) return p[mid];
        else if (p[mid] > n) hi = mid-1;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    return -1;  // Value could not be found
}

/*
Return a sorted vector of all palindromes that are a product of two three-digit
numbers.
*/
std::vector<int> get_palindromes() {
    std::vector<int> p;
    for (int i = 1; i < 1000; ++i) {
        for (int j = 1; j < 1000; ++j) {
            if (is_palindrome(i * j))
                p.push_back(i * j);
        }
    }
    std::sort(p.begin(), p.end());
    return p;
}
