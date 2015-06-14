#include <iostream>
#include <string>

std::string password(int n);

int main() {
    int t;
    std::cin >> t;
    int n;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << password(n) << std::endl;
    }
    return 0;
}

std::string password(int n) {
    std::string pswd = "";
    
}
