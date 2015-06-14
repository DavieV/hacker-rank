#include <iostream>
#include <string>
#include <algorithm>

bool is_pangram(std::string line);

int main() {
    std::string line;
    std::getline(std::cin, line);
    if (is_pangram(line))
        std::cout << "pangram" << std::endl;
    else
        std::cout << "not pangram" << std::endl;
    return 0;
}

bool is_pangram(std::string line) {
    int occur[26] = {0};

    // Convert line to all lowercase
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);

    for (char c : line) {
        if (c != ' ')
            ++occur[c - 'a'];
    }

    for (int i : occur) {
        if (i == 0)
            return false;
    }
    return true;
}
