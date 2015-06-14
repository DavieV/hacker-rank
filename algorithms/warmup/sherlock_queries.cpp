#include <iostream>
#include <cmath>

int main() {
    int m, n;
    std::cin >> n >> m;
    int A[n], B[m], C[m];
    int tmp;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        A[i] = tmp;
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> tmp;
        B[i] = tmp;
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> tmp;
        C[i] = tmp;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j % B[i] == 0)
                A[j] *= C[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << A[i] % (int(pow(10,9)) + 7) << std::endl;
    }
}
