#include <iostream>
#include <string>

int change(std::string s);

int main() {
    int t;
    std::string s;

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> s;
        std::cout << change(s) << std::endl;
    }

    return 0;
}

int change(std::string s) {
    if (s.size() % 2 != 0)
        return -1;

    std::string s1 = s.substr(0, s.size()/2);
    std::string s2 = s.substr(s.size()/2);

    int occur1[26] = {0};
    int occur2[26] = {0};

    for (int i = 0; i < s1.size(); ++i) {
        ++occur1[s1[i]-'a'];
        ++occur2[s2[i]-'a'];
    }

    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (occur2[i] - occur1[i] > 0)
            cnt += (occur2[i] - occur1[i]);
    }

    return cnt;
}
