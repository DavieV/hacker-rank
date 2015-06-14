#include <iostream>
#include <vector>

void partition(int len, int ar[]);
void print_array(int len, int ar[]);

int main() {
    int n;
    std::cin >> n;
    int ar[n], tmp;

    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        ar[i] = tmp;
    }

    partition(n, ar);
    print_array(n, ar);
    return 0;
}

void print_array(int len, int ar[]) {
    for (int i = 0; i < len; ++i)
        std::cout << ar[i] << " ";
    std::cout << std::endl;
}

void partition(int len, int ar[]) {
    int p = ar[0];
    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < len; ++i) {
        if (ar[i] < p)
            left.push_back(ar[i]);
        if (ar[i] > p)
            right.push_back(ar[i]);
    }

    for (int i = 0; i < left.size(); ++i)
        ar[i] = left[i];

    ar[left.size()] = p;

    for (int i = 0; i < right.size(); ++i)
        ar[left.size()+i+1] = right[i];
}
