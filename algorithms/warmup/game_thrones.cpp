#include <iostream>
#include <string>

bool valid(std::string w);

int main() {
    std::string word;
    std::cin >> word;
    if (valid(word))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}

bool valid(std::string w) {
    int occur[27];
    for (int i = 0; i < 27; ++i)
        occur[i] = 0;

    for (int i = 0; i < w.length(); ++i) {
        ++occur[w[i]-'a'];
    }

    bool mid = false;
    for (int i = 0; i < 27; ++i) {
        if (occur[i] % 2 != 0) {
            if (mid == false)
                mid = true;
            else
                return false;
        }
    }

    return true;
}
