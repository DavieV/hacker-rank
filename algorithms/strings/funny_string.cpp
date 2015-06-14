#include <string>
#include <iostream>

bool funny(std::string);
int my_abs(int);

int main() {
    int n;
    std::cin >> n;
    std::string s;

    for (int i = 0; i != n; ++i) {
        std::cin >> s;
        if (funny(s))
            std::cout << "Funny" << std::endl;
        else
            std::cout << "Not Funny" << std::endl;
    }

    return 0;
}

bool funny(std::string s) {
    int l = s.length();
    for (int i = 1; i != l; ++i) {
        if (my_abs(s[i] - s[i-1]) != my_abs(s[l-i-1] - s[l-i]))
            return false;
    }
    return true;
}

int my_abs(int n) {
    if (n < 0)
        return -n;
    return n;
}
