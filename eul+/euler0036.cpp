#include <iostream>
#include <string>

bool base_palindrome(int, int);
bool num_palindrome(int);
int num_reverse(int);

int main() {
    int n, b;
    int sum = 0;

    std::cin >> n >> b;

    for (int i = 1; i != n; ++i) {
        if (num_palindrome(i) && base_palindrome(b, i))
            sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}

bool base_palindrome(int b, int n) {
    std::string result;
    while (n > 0) {
        result += (n % b) + '0';
        n /= b;
    }

    unsigned len = result.length();
    for (unsigned i = 0; i < len / 2; ++i) {
        if (result[i] != result[len - i - 1])
            return false;
    }

    return true;
}

bool num_palindrome(int n) {
    return n == num_reverse(n);
}

int num_reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }
    return rev;
}
