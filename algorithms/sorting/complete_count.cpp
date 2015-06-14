#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int main() {
    int n, freq[100];
    memset(freq, 0, sizeof(freq));
    std::cin >> n;
    int tmp_int;
    std::string tmp_str
    std::vector<int> nums;
    std::vector<std::string> words;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp_int;
        std::cin >> tmp_str;
        ++freq[tmp_int];
        nums.push_back(tmp_int);
        if (i < n/2)
            words.push_back("-");
        else
            words.push_back(tmp_str);
    }


    return 0;
}
