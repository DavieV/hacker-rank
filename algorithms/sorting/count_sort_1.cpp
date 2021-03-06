#include <iostream>
#include <cstring>

int main() {
    int n; 
    int count[100];
    memset(count, 0, sizeof(count));
    std::cin >> n;
    int tmp;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        ++count[tmp];
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << count[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
