#include <iostream>

int main() {
    int n, t;
    std::cin >> n >> t;

    int road[n];

    for (int i = 0; i != n; ++i)
        std::cin >> road[i];

    int a, b;
    for (int i = 0; i != t; ++i) {
        std::cin >> a >> b;
        int min = 3;

        for (int x = a; x <= b; ++x) {
            if (road[x] < min)
                min = road[x];
        }

        std::cout << min << std::endl;
    }


}
