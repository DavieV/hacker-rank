#include <iostream>
#include <algorithm>

void display_array(int ar[], int len);
void swap(int *a, int *b);

int main() {
    int len;
    std::cin >> len;
    int ar[len];
    int tmp;
    for (int i = 0; i < len; ++i) {
        std::cin >> tmp;
        ar[i] = tmp;
    }

    int pos;
    for (int i = 1; i < len; ++i) {
        pos = i;
        while (pos > 0 && ar[pos] < ar[pos-1]) {
            swap(&ar[pos], &ar[pos-1]);
            --pos;
        }
        display_array(ar, len);
    }

    return 0;
}

void display_array(int ar[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
