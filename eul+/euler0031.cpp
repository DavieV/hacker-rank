#include <iostream>
#include <cstring>

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};  // Array of coin values
int dag[100001][8];  // Graph used for dynamic programming caching

int coin_change(int, int);

int main() {
    int t, n;

    memset(dag, -1, sizeof(dag));

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << coin_change(n, 7) << std::endl;
    }

    return 0;
}

int coin_change(int n, int m) {
    if (n == 0) return 1;
    if (n < 0 || m < 0) return 0;
    if (dag[n][m] != -1) return dag[n][m];

    int ans = coin_change(n, m - 1) + coin_change(n - coins[m], m);
    ans %= 1000000007;
    return dag[n][m] = ans;
}
