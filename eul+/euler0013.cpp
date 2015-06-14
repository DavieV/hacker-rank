/*
* Output the first 4 digits of the sum of 100 50-digit numbers
*/

#include <iostream>
#include <string>

std::string addRows(std::string, std::string);
std::string addZeroes(std::string, int);

int main(void) {
    int t;
    std::cin >> t;

    std::string sum = "0";
    std::string tmp;
    for (int i = 0; i < t; ++i) {
        std::cin >> tmp;
        sum = addRows(sum, tmp);
    }
    for (int i = 0; i < 10; ++i)
        std::cout << sum[i];
    std::cout << std::endl;
}

std::string addRows(std::string a, std::string b) {
    std::string sum;
    int carry = 0;
    int digit;
    char tmp;
    if (a.length() < b.length()) a = addZeroes(a, b.length() - a.length());
    if (b.length() < a.length()) b = addZeroes(b, a.length() - b.length());

    for (int i = a.length() - 1; i >= 0; i--) {
        digit = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
        carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
        tmp = digit + '0';
        sum = tmp + sum;
    }
    if (carry != 0) {
        tmp = carry + '0';
        sum = tmp + sum;
    }
    return sum;
}

std::string addZeroes(std::string num, int amount) {
    std::string zeroes = "";
    for (int i = 0; i < amount; i++) {
        zeroes += '0';
    }
    return zeroes + num;
}
