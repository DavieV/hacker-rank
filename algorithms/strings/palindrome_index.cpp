#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

bool palindrome(std::string s);
int find_index(std::string s);
std::string reverse(std::string s);

int main() {
    int t;
    std::string s;

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> s;
        std::cout << find_index(s) << std::endl;
    }

    return 0;
}

int find_index(std::string s) {
    if (palindrome(s))
        return -1;

    std::string r = reverse(s);

    int index1, index2;
    int l = s.length();

    for (int i = 0; i < l; ++i) {
        if (s[i] != r[i]) {
            index1 = i;
            index2 = l - i - 1;
        }
    }

    s.erase(std::begin(s)+index1);

    if (palindrome(s))
        return index1;
    return index2;
}

bool palindrome(std::string s) {
    int l = s.length();
    for (int i = 0; i < l / 2; ++i) {
        if (s[i] != s[l-i-1])
            return false;
    }
    return true;
}

std::string reverse(std::string s) {
    int l = s.length();

    for (int i = 0; i < l / 2; ++i) {
        std::swap(s[i], s[l-i-1]);
    }

    return s;
}
