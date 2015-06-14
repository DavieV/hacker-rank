#include <iostream>
#include <map>

void fill_map(std::map<long long, bool> &);

int main() {
    std::map<long long, bool> fib;
    fill_map(fib);
    int c;
    long long n;
    std::cin >> c;

    for (int i = 0; i < c; ++i) {
        std::cin >> n;
        if (fib.find(n) != fib.end())
            std::cout << "IsFibo" << std::endl;
        else
            std::cout << "IsNotFibo" << std::endl;
    }

    return 0;
}

void fill_map(std::map<long long, bool> &fib) {
    long long p1 = 0, p2 = 1, cur = 1;
    fib[p1] = true;
    fib[p2] = true;
    while (cur < 10000000000LL) {
        p1 = p2;
        p2 = cur;
        cur = p1 + p2;
        fib[cur] = true;
    }
}
