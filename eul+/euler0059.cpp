#include <iostream>
#include <string>
#include <vector>
#include <map>

int find_int(std::vector<int> group);

int main() {
    int n;
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    std::cin >> n;

    int pos = 1;
    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        switch (pos) {
        case 1:
            first.push_back(tmp);
            pos = 2;
            break;
        case 2:
            second.push_back(tmp);
            pos = 3;
            break;
        case 3:
            third.push_back(tmp);
            pos = 1;
            break;
        }
    }

    char p1 = find_int(first);
    char p2 = find_int(second);
    char p3 = find_int(third);

    std::cout << p1 << p2 << p3 << std::endl;

    return 0;
}

/*
This function makes the assumption that the most occuring intacter in a
message is the space. By finding the most frequent encoded intacter and
XORing it with ASCII 32, the password intacter can be found.
*/
int find_int(std::vector<int> group) {
    std::map<int, int> freq;
    for (int c : group) {
        if (freq.find(c) == freq.end()) {
            freq[c] = 1;
        } else {
            ++freq[c];
        }
    }

    int max = 0;
    int most;
    for (int c : group) {
        if (freq[c] > max) {
            max = freq[c];
            most = c;
        }
    }
    return most ^ 32;
}
