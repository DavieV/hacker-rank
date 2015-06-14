#include <iostream>

void display_list(int ar[], int len);

int main() {
    int s, tmp;
    int ar[s];

    std::cin >> s;
    for (int i = 0; i < s - 1; ++i) {
        std::cin >> tmp;
        ar[i] = tmp;
    }

    int num, index = s - 1;
    std::cin >> num;

    while (num < ar[index-1]) {
        ar[index] = ar[index-1];
        display_list(ar, s);
        --index;
    }
    ar[index] = num;
    display_list(ar, s);

    return 0;
}

void display_list(int ar[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}
