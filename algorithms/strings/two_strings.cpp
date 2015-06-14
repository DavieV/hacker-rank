// Determine if two strings share a common substring (share at least one character)

#include <iostream>
#include <string>
#include <set>

bool common(std::string, std::string);

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i != T; ++i) {
        std::string A;
        std::string B;
        std::cin >> A >> B;

        if (common(A, B))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}

bool common(std::string a, std::string b) {
    std::set<char> s;

    for (auto c : a)
        s.insert(c);

    for (auto c : b)
        if (s.find(c) != s.end())
            return true;

    return false;
}
