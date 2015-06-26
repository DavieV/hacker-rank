#include <iostream>
#include <string>

uint64_t num_reverse(uint64_t);
uint32_t num_len(uint64_t);
std::string num_to_words(uint64_t);

int main() {
    int t;
    uint64_t n;

    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cout << num_to_words(n) << std::endl;
    }

    return 0;
}

uint32_t num_len(uint64_t n) {
    uint32_t len = 0;
    while (n > 0) {
        ++len;
        n /= 10;
    }
    return len;
}

// This function hurt me to write more than it hurts you to read.
std::string num_to_words(uint64_t n) {
    std::string ones[10] =
    {"", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine"};

    std::string teens[10] =
    {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    std::string tens[10] =
    {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
    "Seventy", "Eighty", "Ninety"};

    std::string s;
    uint32_t len;

    while (n > 0) {
        len = num_len(n);

        // One digit number (1, 9)
        if (len == 1) {
            s += ones[n];
            n /= 10UL;
        }

        // Two digit number [10^1, 10^2)
        else if (len == 2) {
            // Special case
            if (n == 10UL)
                s += tens[1];
            // Number is in the teens
            else if (n < 20)
                s += teens[n%10UL];
            else
                s += tens[n/10UL] + " " + ones[n%10UL];
            n /= 100UL;  // end the loop by dividing out remainder of digits
        }

        // Three digit number [10^2, 10^3)
        else if (len == 3) {
            s += ones[n/100UL] + " Hundred ";
            n %= 100UL;  // Grab remaining 2 digits
        }

        // Four digit number [10^3, 10^4)
        else if (len == 4) {
            s += ones[n/1000UL] + " Thousand ";
            n %= 1000UL;  // Grab remaining 3 digits
        }


        // Five digit numbers [10^4, 10^5)
        else if (len == 5) {
            uint32_t front = n / 1000UL;  // Front 2 digits
            if (front < 20) {
                if (front == 10)
                    s += tens[1];
                else
                    s += teens[front%10];
            } else {
                s += tens[front/10] + " " + ones[front%10];
            }
            s += " Thousand ";
            n %= 1000UL;  // Grab the 3 remaining digits
        }

        // Six digit number [10^5, 10^6)
        else if (len == 6) {
            if (n % 100000UL == 0) {
                s += ones[n/100000UL] + " Hundred Thousand ";
                break;
            }
            s += ones[n/100000UL] + " Hundred ";
            n %= 100000UL;  // Grab the remaining 5 digits
        }

        // Seven digit number [10^6, 10^7)
        else if (len == 7) {
            s += ones[n/1000000UL] + " Million ";
            n %= 1000000UL;  // Grab remaining 6 digits
        }

        // Eight digit number [10^7, 10^8)
        else if (len == 8) {
            uint32_t front = n / 1000000UL;  // Front 2 digits
            if (front < 20) {
                if (front == 10)
                    s += tens[1];
                else
                    s += teens[front%10];
            } else {
                s += tens[front/10] + " " + ones[front%10];
            }
            s += " Million ";
            n %= 1000000UL;  // Grab remaining 6 digits
        }

        // Nine digit number [10^8, 10^9)
        else if (len == 9) {
            if (n % 100000000UL == 0) {
                s += ones[n/100000000UL] + " Hundred Million ";
                break;
            }
            s += ones[n/100000000UL] + " Hundred ";
            n %= 100000000UL;  // Grab remaining 8 digits
        }

        // Ten digit number [10^9, 10^10)
        else if (len == 10) {
            s += ones[n/1000000000UL] + " Billion ";
            n %= 1000000000UL;  // Grab remaining 9 digits
        }

        // Eleven digit number [10^10, 10^11)
        else if (len == 11) {
            uint32_t front = n / 1000000000UL;  // Front 2 digits
            if (front < 20) {
                if (front == 10)
                    s += tens[1];
                else
                    s += teens[front%10];
            } else {
                s += tens[front/10] + " " + ones[front%10];
            }
            s += " Billion ";
            n %= 1000000000UL;  // Grab remaining 9 digits
        }

        // Twelve digit number [10^11, 10^12)
        else if (len == 12) {
            if (n % 100000000000UL == 0) {
                s += ones[n/100000000000UL] + " Hundred Billion ";
                break;
            }
            s += ones[n/100000000000UL] + " Hundred ";
            n %= 100000000000UL;  // Grab remaining 11 digits
        }

        // std::cout << s.length() << std::endl;
    }

    std::string output;

    for (uint32_t i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            output += s[i];
        } else {
            if (i + 1 < s.length() && s[i+1] != ' ')
                output += s[i];
        }
    }

    return output;
}
